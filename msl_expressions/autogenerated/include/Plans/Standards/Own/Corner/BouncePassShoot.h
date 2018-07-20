#ifndef BouncePassShoot_H_
#define BouncePassShoot_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1459357144291) ENABLED START*/ //Add additional includes here
namespace msl
{
    class MovementQuery;
}
namespace geometry
{
    class CNPosition;
    class CNPoint2D;
}
/*PROTECTED REGION END*/
namespace alica
{
    class BouncePassShoot : public DomainBehaviour
    {
    public:
        BouncePassShoot();
        virtual ~BouncePassShoot();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1459357144291) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1459357144291) ENABLED START*/ //Add additional protected methods here
        shared_ptr<geometry::CNPosition> ownPos;
        shared_ptr<geometry::CNPoint2D> egoBallPos;
        string planName;
        string teamMateTaskName;
        EntryPoint* receiver;
        int counter;
        double driveSlowSpeed;
        shared_ptr<msl::MovementQuery> query;
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1459357144291) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* BouncePassShoot_H_ */
