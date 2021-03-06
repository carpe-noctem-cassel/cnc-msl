#ifndef ReleaseOwnHalfCONSTRAINT_H_
#define ReleaseOwnHalf_H_
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

    class Constraint1458033759784 : public BasicConstraint
    {
        void getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan> rp);
    };

} /* namespace alica */

#endif /* ReleaseOwnHalfCONSTRAINT_H_ */
