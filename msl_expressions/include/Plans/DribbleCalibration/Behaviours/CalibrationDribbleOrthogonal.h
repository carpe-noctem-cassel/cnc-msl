#ifndef CalibrationDribbleOrthogonal_H_
#define CalibrationDribbleOrthogonal_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1469196321064) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class CalibrationDribbleOrthogonal : public DomainBehaviour
    {
    public:
        CalibrationDribbleOrthogonal();
        virtual ~CalibrationDribbleOrthogonal();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1469196321064) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1469196321064) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1469196321064) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* CalibrationDribbleOrthogonal_H_ */
