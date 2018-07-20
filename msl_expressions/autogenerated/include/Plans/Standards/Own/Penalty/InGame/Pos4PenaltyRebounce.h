#ifndef Pos4PenaltyRebounce_H_
#define Pos4PenaltyRebounce_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1466972686566) ENABLED START*/ //Add additional includes here
namespace msl
{
    class MovementQuery;
}
namespace geometry
{
    class CNPoint2D;
}
/*PROTECTED REGION END*/
namespace alica
{
    class Pos4PenaltyRebounce : public DomainBehaviour
    {
    public:
        Pos4PenaltyRebounce();
        virtual ~Pos4PenaltyRebounce();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1466972686566) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1466972686566) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1466972686566) ENABLED START*/ //Add additional private methods here
        shared_ptr<geometry::CNPoint2D> alloTarget;
        shared_ptr<msl::MovementQuery> query;
        double translation;
        double catchRadius;
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Pos4PenaltyRebounce_H_ */
