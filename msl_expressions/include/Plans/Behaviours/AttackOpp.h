#ifndef AttackOpp_H_
#define AttackOpp_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1430324527403) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class AttackOpp : public DomainBehaviour
    {
    public:
        AttackOpp();
        virtual ~AttackOpp();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1430324527403) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1430324527403) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1430324527403) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* AttackOpp_H_ */
