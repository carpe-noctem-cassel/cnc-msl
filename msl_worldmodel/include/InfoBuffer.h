#pragma once

#include "InformationElement.h"

#include <nonstd/optional.hpp>

#include <memory>
#include <mutex>
#include <typeinfo>

namespace msl
{
/**
 * Information buffer of shared_ptr of a given data type.
 */
template <typename T>
class InfoBuffer
{
  public:
    /**
     * Default constructor.
     * @param bufferSize Number of elements which can be stored within the information buffer
     */
    InfoBuffer(const int bufferSize)
        : mtx_()
    {
        this->bufferSize = bufferSize;
        this->infoElementCounter = 0;
        this->index = -1;
        this->ringBuffer = new std::shared_ptr<const InformationElement<T>>[this->bufferSize];
    }

    /**
      * Copy constructor.
      * YOU SHALL NOT COPY!
      * Copying the ringbuffer isn't trivial, InformationElement can contain raw objects or shared_pointers...
      * Also you most likely don't want to copy a whole buffer.
      * If you REALLY need to copy the buffer, do it by hand.
      */
    InfoBuffer(const InfoBuffer &obj) = delete;
    // TODO: delete?
    /*InfoBuffer(const InfoBuffer &obj)
        : mtx_()
    {
        // Do not copy the mutex!
        this->bufferSize = obj.bufferSize;
        this->infoElementCounter = obj.infoElementCounter;
        this->index = obj.index;

        auto buffer = new std::shared_ptr<const InformationElement<T>>[this->bufferSize];
        this->ringBuffer = make_shared<>(*obj.ringBuffer);
    }*/

    /**
     *  Default destructor.
     */
    virtual ~InfoBuffer()
    {
        delete[] this->ringBuffer;
    }

    /**
     * Return the buffer size.
     * @return the buffer size.
     */
    const int getBufferSize() const
    {
        return this->bufferSize;
    }

    /**
     * Returns the current number of elements within the information buffer.
     * @return the current number of elements within the information buffer.
     */
    const int getSize() const
    {
        return (this->bufferSize < this->infoElementCounter) ? this->bufferSize : this->infoElementCounter;
    }

    /**
     * Clears the buffer. If cleanBuffer is false only the index structure is reset, but the
     * buffer still exists (old elements are not accessible). If cleanBuffer is true the
     * pointers from the buffer are cleared as well.
     * @param cleanBuffer True to clear the buffer.
     */
    void clear(bool cleanBuffer)
    {
        std::lock_guard<std::mutex> guard(mtx_);
        this->index = -1;
        this->infoElementCounter = 0;

        if (cleanBuffer)
        {
            std::shared_ptr<const InformationElement<T>> element;
            for (int i = 0; i < this->bufferSize; ++i)
                this->ringBuffer[i] = element;
        }
    }

    /**
     * Returns the type_info of the used template type.
     * @return The type_info of the used template type.
     */
    const std::type_info *getTypeInfo() const
    {
        return &typeid(T);
    }

    /**
     * Sets the out parameter to the n-th last element, if it exists.
     * @param out This out parameter will be set if possible.
     * @param n States that the n-th last element should be set to the out parameter.
     * @return True if the n-th last element exists, false otherwise.
     */
    const std::shared_ptr<const InformationElement<T>> getLast(const int n = 0) const
    {
        std::lock_guard<std::mutex> guard(mtx_);

        if (this->index < 0 || this->bufferSize <= n || this->infoElementCounter <= n)
        {
            return nullptr;
        }

        return this->ringBuffer[(this->index - n) % this->bufferSize];
    }

    /**
     * Gets the last valid element
     * If you only need the content of the InformationElement you can use @see InfoBuffer::getLastValidContent()
     * @see InformationElement::isValid()
     * @return a shared_ptr to the element, nullptr if none found
     */
    const std::shared_ptr<const InformationElement<T>> getLastValid() const
    {
        std::lock_guard<std::mutex> guard(mtx_);

        if (this->index < 0 || this->bufferSize <= 0 || this->infoElementCounter <= 0)
        {
            return nullptr;
        }

        int limit = std::min((unsigned long long)this->bufferSize, this->infoElementCounter);
        for (int i = 0; i < limit; i++)
        {
            int index = (this->index - i) % this->bufferSize;
            if (this->ringBuffer[index]->isValid())
            {
                return this->ringBuffer[index];
            }
        }
        return nullptr;
    }

    /**
     * Gets the content of the last valid element
     * @see InformationElement::isValid()
     * @return optional with the content of the last valid element, nullopt if none found
     */
    const nonstd::optional<T> getLastValidContent() const
    {
        auto lastValid = this->getLastValid();

        if(lastValid == nullptr) {
            return nonstd::nullopt;
        }

       return lastValid->getInformation();
    }

    /**
     * Gets the element closest to the specified time
     * @param time to search for
     * @return a shared_ptr to the element if found, else nullptr (empty buffer)
     */
    const std::shared_ptr<const InformationElement<T>> getTemporalCloseTo(const InfoTime time) const
    {
        std::lock_guard<std::mutex> guard(mtx_);

        if (this->index < 0 || this->bufferSize <= 0 || this->infoElementCounter <= 0)
        {
            return nullptr;
        }

        auto closest = std::make_shared<const InformationElement<T>>;

        InfoTime timeDiffOfClosest = std::numeric_limits<long long>::max();
        int numberOfAvailableElements = std::min(this->bufferSize, this->infoElementCounter);
        for (int i = 0; i < numberOfAvailableElements; i++)
        {
            int index = (this->index - i) % this->bufferSize;
            InfoTime curTimeDiff = std::abs(time - this->ringBuffer[index]->getCreationTime());
            if (curTimeDiff < timeDiffOfClosest)
            {
                closest = this->ringBuffer[index];
                timeDiffOfClosest = curTimeDiff;
            }
            else
            {
                /*
                * We found the information closest to time in the last iteration,
                * because the ringBuffer is sorted.
                */
                break;
            }
        }

        return closest;
    }

    /**
     * Gets the element closest to the specified time within the given threshold
     * @param time to search for
     * @param maxTimeDiff maximum offset to given time
     * @return a shared_ptr to the element if found, else nullptr
     */
    const std::shared_ptr<const InformationElement<T>> getTemporalCloseTo(const InfoTime time,
                                                                          const InfoTime maxTimeDiff) const
    {
        auto closest = this->getTemporalCloseTo(time);

        if (!closest || std::abs(time - closest->getCreationTime()) > maxTimeDiff)
        {
            return nullptr;
        }
        else
        {
            return closest;
        }
    }

    /**
     * Adds a new element to the information buffer, if it older than the last added element.
     * @param element The element to add.
     * @return True if the element was added, False otherwise.
     */
    bool add(const std::shared_ptr<const InformationElement<T>> element)
    {
        std::lock_guard<std::mutex> guard(mtx_);

        auto last = this->getLast();

        // only allow newer information
        if (last && element->getCreationTime() < last->getCreationTime())
        {
            return false;
        }

        this->infoElementCounter++;
        this->index = (++this->index) % this->bufferSize;
        this->ringBuffer[index] = element;

        return true;
    }

  private:
    mutable std::mutex mtx_;
    std::shared_ptr<const InformationElement<T>> *ringBuffer; /**< Ring buffer of elements */
    int bufferSize;                                           /**< number of stored elements */
    int index;                                                /**< Current index of the last added element */
    unsigned long long infoElementCounter;                    /**< Counter of elements added to the buffer */
};

} /* namespace msl */