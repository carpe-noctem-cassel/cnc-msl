#ifndef RotationCalibrationCalculation_H_
#define RotationCalibrationCalculation_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1475074396562) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class RotationCalibrationCalculation : public DomainBehaviour
    {
    public:
        RotationCalibrationCalculation();
        virtual ~RotationCalibrationCalculation();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1475074396562) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1475074396562) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1475074396562) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* RotationCalibrationCalculation_H_ */
