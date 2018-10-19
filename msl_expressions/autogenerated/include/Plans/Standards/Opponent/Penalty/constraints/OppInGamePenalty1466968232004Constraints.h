#ifndef OppInGamePenaltyCONSTRAINT_H_
#define OppInGamePenalty_H_
#include "engine/BasicConstraint.h"
#include <memory>

using namespace std;
using namespace alica;

namespace alica
{
    class ProblemDescriptor;
    class RunningPlan;
}

namespace alicaAutogenerated
{

    class Constraint1466975666362 : public BasicConstraint
    {
        void getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp);
    };

} /* namespace alica */

#endif /* OppInGamePenaltyCONSTRAINT_H_ */