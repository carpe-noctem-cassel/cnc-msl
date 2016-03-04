#include "Plans/Attack/constraints/AttackPlay1434045709191Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1434045709191) ENABLED START*/
//Add additional using directives here
#include "MSLFootballField.h"
#include "MSLWorldModel.h"
#include "engine/constraintmodul/ConstraintDescriptor.h"
#include "engine/RunningPlan.h"
#include "engine/Assignment.h"
#include "AutoDiff.h"
#include "MSLConstraintBuilder.h"

/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
    //Plan:AttackPlay

    /*		
     * Tasks: 
     * - EP:1434045709194 : Attack (1222613952469)
     * - EP:1434045719840 : AttackSupport (1225115536468)
     * - EP:1434045723977 : Defend (1225115406909)
     * - EP:1434112675755 : InGamePassReceiver (1307185798142)
     *
     * States:
     * - Attack (1434045709193)
     * - MidFieldDefense (1434045868018)
     * - Defend (1434045870617)
     * - Release (1434112762535)
     * - ApproachPass (1436536084172)
     * - InterceptPass (1436536085953)
     * - InterceptPass (1436536121614)
     * - ApproachPass (1436536123918)
     *
     * Vars:				
     * - TargetX (1457002241973) 				
     * - TargetY (1457002247256) 
     */

    /*
     * RuntimeCondition - (Name): NewRuntimeCondition
     * (ConditionString): 
     * Static Variables: [TargetX, TargetY]
     * Domain Variables:

     */
    void Constraint1434112519736::getConstraint(shared_ptr<ConstraintDescriptor> c, shared_ptr<RunningPlan> rp)
    {
        /*PROTECTED REGION ID(cc1434112519736) ENABLED START*/
        /*PROTECTED REGION END*/
    }

// State: Attack

// State: Attack

// State: MidFieldDefense

// State: MidFieldDefense

// State: Defend

// State: Defend

// State: Release

// State: Release

// State: ApproachPass

// State: ApproachPass

// State: InterceptPass

// State: InterceptPass

// State: InterceptPass

// State: InterceptPass

// State: ApproachPass

// State: ApproachPass

}
