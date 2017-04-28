#ifndef AdvancdeSimplePass_H_
#define AdvancdeSimplePass_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1450176193656) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class AdvancdeSimplePass : public DomainBehaviour
    {
    public:
        AdvancdeSimplePass();
        virtual ~AdvancdeSimplePass();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1450176193656) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1450176193656) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1450176193656) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* AdvancdeSimplePass_H_ */
