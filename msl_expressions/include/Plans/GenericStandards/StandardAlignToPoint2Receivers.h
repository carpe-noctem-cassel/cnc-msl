#ifndef StandardAlignToPoint2Receivers_H_
#define StandardAlignToPoint2Receivers_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1467228931063) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class StandardAlignToPoint2Receivers : public DomainBehaviour
    {
    public:
        StandardAlignToPoint2Receivers();
        virtual ~StandardAlignToPoint2Receivers();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1467228931063) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1467228931063) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1467228931063) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* StandardAlignToPoint2Receivers_H_ */
