#ifndef Pos4Def_H_
#define Pos4Def_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1445438142979) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
    class Pos4Def : public DomainBehaviour
    {
    public:
        Pos4Def();
        virtual ~Pos4Def();
        virtual void run(void* msg);
        /*PROTECTED REGION ID(pub1445438142979) ENABLED START*/ //Add additional public methods here
        /*PROTECTED REGION END*/
    protected:
        virtual void initialiseParameters();
        /*PROTECTED REGION ID(pro1445438142979) ENABLED START*/ //Add additional protected methods here
        /*PROTECTED REGION END*/
    private:
        /*PROTECTED REGION ID(prv1445438142979) ENABLED START*/ //Add additional private methods here
        /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* Pos4Def_H_ */
