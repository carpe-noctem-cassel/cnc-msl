#ifndef CalibrationDribbleForward_H_
#define CalibrationDribbleForward_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1469116853584) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class CalibrationDribbleForward : public DomainBehaviour
    {
    public:
        CalibrationDribbleForward();
        virtual ~CalibrationDribbleForward();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1469116853584) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1469116853584) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1469116853584) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* CalibrationDribbleForward_H_ */
