#ifndef CatchPass_H_
#define CatchPass_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1440754525537) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class CatchPass : public DomainBehaviour
    {
    public:
        CatchPass();
        virtual ~CatchPass();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1440754525537) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1440754525537) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1440754525537) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* CatchPass_H_ */
