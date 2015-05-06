#include "ConstraintCreator.h"
#include <iostream>

#include  "Plans/GameStrategy/Other/constraints/Parking1426695119330Constraints.h"

#include  "Plans/GameStrategy/OppStandards/constraints/OppStandards1426694865227Constraints.h"

#include  "Plans/GameStrategy/Other/constraints/SimpleDropBall1426696586622Constraints.h"

#include  "Plans/Defence/Test/constraints/TestApproachBallMaster1430324312981Constraints.h"

#include  "Plans/GameStrategy/OppStandards/constraints/GenericOppStandard1426697871183Constraints.h"

#include  "Plans/ActuatorTest/constraints/ActuatorTestMaster1417017436952Constraints.h"

#include  "Plans/GameStrategy/Other/constraints/DroppedBall1426694906399Constraints.h"

#include  "Plans/GameStrategy/OwnStandards/constraints/GenericOwnStandardPositioning1428507630593Constraints.h"

#include  "Plans/TwoHoledWall/constraints/ShootTwoHoledWall1417620189234Constraints.h"

#include  "Plans/GameStrategy/OwnStandards/constraints/GenericOwnStandardExecution1428508782222Constraints.h"

#include  "Plans/GameStrategy/OppStandards/constraints/GenericOppStandardExecuter1429109528736Constraints.h"

#include  "Plans/constraints/WM161413992564408Constraints.h"

#include  "Plans/TwoHoledWall/constraints/TwoHoledWallMaster1417621468963Constraints.h"

#include  "Plans/GameStrategy/OwnStandards/constraints/GenericOwnStandard1426697860439Constraints.h"

#include  "Plans/GameStrategy/OppStandards/constraints/GenericOppStandardPositioning1429108230432Constraints.h"

#include  "Plans/GameStrategy/Gameplay/constraints/Gameplay1426694853089Constraints.h"

#include  "Plans/GameStrategy/OwnStandards/constraints/OwnStandards1426694875113Constraints.h"

using namespace std;
using namespace alicaAutogenerated;

namespace alica
{

    ConstraintCreator::ConstraintCreator()
    {
    }

    ConstraintCreator::~ConstraintCreator()
    {
    }

    shared_ptr<BasicConstraint> ConstraintCreator::createConstraint(long constraintConfId)
    {
        switch (constraintConfId)
        {

            default:
                cerr << "ConstraintCreator: Unknown constraint requested: " << constraintConfId << endl;
                throw new exception();
                break;
        }
    }

}
