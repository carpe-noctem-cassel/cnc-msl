#ifndef CornerKick_H_
#define CornerKick_H_

#include "DomainCondition.h"
#include "engine/BasicUtilityFunction.h"
#include "engine/UtilityFunction.h"
#include "engine/DefaultUtilityFunction.h"
/*PROTECTED REGION ID(incl1462373376006) ENABLED START*/
//Add inlcudes here
/*PROTECTED REGION END*/
using namespace alica;

namespace alicaAutogenerated
{
    /*PROTECTED REGION ID(meth1462373376006) ENABLED START*/
    //Add other things here
    /*PROTECTED REGION END*/
    class UtilityFunction1462373376006 : public BasicUtilityFunction
    {
        shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
    };

    class RunTimeCondition1464793807994 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1464784053079 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1464792277148 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1464787990119 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1464788000901 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1464788060652 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

    class TransitionCondition1464796139312 : public DomainCondition
    {
        bool evaluate(shared_ptr<RunningPlan> rp);
    };

} /* namespace alica */

#endif
