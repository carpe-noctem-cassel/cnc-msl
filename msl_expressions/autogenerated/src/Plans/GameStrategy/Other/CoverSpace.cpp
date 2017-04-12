using namespace std;
#include "Plans/GameStrategy/Other/CoverSpace.h"

/*PROTECTED REGION ID(inccpp1455537892946) ENABLED START*/ //Add additional includes here
#include <msl_robot/robotmovement/RobotMovement.h>
#include <Ball.h>
#include <RawSensorData.h>
#include <MSLWorldModel.h>
#include <MSLFootballField.h>
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1455537892946) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    CoverSpace::CoverSpace() :
            DomainBehaviour("CoverSpace")
    {
        /*PROTECTED REGION ID(con1455537892946) ENABLED START*/ //Add additional options here
    	positionPercentage = 0;
        /*PROTECTED REGION END*/
    }
    CoverSpace::~CoverSpace()
    {
        /*PROTECTED REGION ID(dcon1455537892946) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void CoverSpace::run(void* msg)
    {
        /*PROTECTED REGION ID(run1455537892946) ENABLED START*/ //Add additional options here
        msl::RobotMovement rm;
        auto alloBallPos = wm->ball->getAlloBallPosition();
        if (!alloBallPos)
        {
            alloBallPos = geometry::CNPointAllo(0, 0);
        }

        auto ownPos = wm->rawSensorData->getOwnPositionVisionBuffer().getLastValidContent();
        if (!ownPos)
        {
            std::cerr << "No own Position!!!! Initiating Self-destruction !!!" << std::endl;
            return;
        }

        //Cover Opposite Side of the field!

        auto alloTarget = alloBallPos;
        if (abs(alloTarget->y) > 1000 || !lastPos)
        {
            alloTarget->y = -alloTarget->y * positionPercentage;
            lastPos = alloTarget;
        }
        else
        {
            //Hysteresis here!
            //1664 = sqrt(2)+robotradius
            alloTarget->y = lastPos->y / abs(lastPos->y) * 1664;
        }

        //Go closer towards own goal according to position percentage
        alloTarget->x = (alloTarget->x + wm->field->getFieldLength() / 2) * positionPercentage
                - wm->field->getFieldLength() / 2;

        //Be sure that the robot is not inside the own penalty area
        if (alloTarget->x < -wm->field->getFieldLength() / 2 + wm->field->getPenaltyAreaLength() + 260)
        {
            alloTarget->x = -wm->field->getFieldLength() / 2 + wm->field->getPenaltyAreaLength() + 260;
        }

        auto egoTarget = alloTarget->toEgo(*ownPos);
        auto egoAlignPoint = alloBallPos->toEgo(*ownPos);

        msl_actuator_msgs::MotionControl mc;
//        mc = msl::RobotMovement::moveToPointCarefully(egoTarget, egoAlignPoint, 100, nullptr);
        query.egoDestinationPoint = egoTarget;
        query.egoAlignPoint = egoAlignPoint;
        query.snapDistance = 100;
        mc = rm.moveToPoint(query);

        if (!std::isnan(mc.motion.translation))
        {
            send(mc);
        }
        else
        {
            cout << "Motion command is NaN!" << endl;
        }

        /*PROTECTED REGION END*/
    }
    void CoverSpace::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1455537892946) ENABLED START*/ //Add additional options here
        lastPos = nonstd::nullopt;
        string tmp;
        bool success = true;
        success &= getParameter("DefensePercentage", tmp);
        try
        {
            if (success)
            {
                positionPercentage = stod(tmp);
            }
        }
        catch (exception& e)
        {
            cerr << "Could not cast the parameter properly" << endl;
        }
        if (positionPercentage > 1)
            positionPercentage = 1;
        if (positionPercentage < 0.1)
            positionPercentage = 0.1;

        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1455537892946) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
