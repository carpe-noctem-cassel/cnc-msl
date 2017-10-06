using namespace std;
#include "Plans/TestPlans/GoalieMotionTuning/DriveToPost.h"

/*PROTECTED REGION ID(inccpp1464189819779) ENABLED START*/ //Add additional includes here
#include "RawSensorData.h"
#include "Game.h"
#include <MSLWorldModel.h>
#include <MSLFootballField.h>
using geometry::CNPointAllo;
/*PROTECTED REGION END*/
namespace alica
{
    /*PROTECTED REGION ID(staticVars1464189819779) ENABLED START*/ //initialise static variables here
    /*PROTECTED REGION END*/
    DriveToPost::DriveToPost() :
            DomainBehaviour("DriveToPost")
    {
        /*PROTECTED REGION ID(con1464189819779) ENABLED START*/ //Add additional options here
        alignMaxVel = (*sc)["Drive"]->get<double>("Drive", "MaxSpeed", NULL);
        snapDistance = (*this->sc)["Behaviour"]->get<int>("Goalie.SnapDistance", NULL);
        goalieSize = (*this->sc)["Behaviour"]->get<int>("Goalie.GoalieSize", NULL);

        alloGoalMid = wm->field->posOwnGoalMid();
        alloGoalLeft = CNPointAllo(alloGoalMid.x + 200, wm->field->posLeftOwnGoalPost().y - goalieSize / 2);
        alloGoalRight = CNPointAllo(alloGoalMid.x + 200, wm->field->posRightOwnGoalPost().y + goalieSize / 2);

        pTrans = (*this->sc)["Behaviour"]->get<double>("Goalie.pTrans", NULL);
        dTrans = (*this->sc)["Behaviour"]->get<double>("Goalie.dTrans", NULL);

        prevTargetDist = 0;
        startTime = -1;
        avgTime = 0.0;

        // 0 stands for left post 1 stands for right post
        driveToPost = 0;
        /*PROTECTED REGION END*/
    }
    DriveToPost::~DriveToPost()
    {
        /*PROTECTED REGION ID(dcon1464189819779) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
    void DriveToPost::run(void* msg)
    {
        /*PROTECTED REGION ID(run1464189819779) ENABLED START*/ //Add additional options here
        ownPos = wm->rawSensorData->getOwnPositionVisionBuffer().getLastValidContent();

        if (!ownPos)
        {
            cout << "[DriveToPost] ownPos null!" << endl;
            return;
        }

        if (wm->game->checkSituation(msl::Situation::Start) && startTime == -1)
        {
            startTime = wm->getTime();
        }

        CNPointAllo targetPost;

        if (driveToPost == 0)
        {
            targetPost = alloGoalLeft;
        }
        else if (driveToPost == 1)
        {
            targetPost = alloGoalRight;
        }

        auto targerPostEgo = targetPost.toEgo(*ownPos);

        if (targetPost.toEgo(*ownPos).length() > snapDistance)
        {
            mc.motion.angle = targetPost.toEgo(*ownPos).angleZ();
            auto alignPoint = CNPointAllo(-ownPos->x, ownPos->y); // align to mirrored ownPos
            mc.motion.rotation = alignPoint.toEgo(*ownPos).rotateZ(M_PI).angleZ();
            mc.motion.translation = std::min(
                    alignMaxVel,
                    (targetPost.toEgo(*ownPos).length() * pTrans)
                            + ((targetPost.toEgo(*ownPos).length() - prevTargetDist) * dTrans));
            prevTargetDist = targetPost.toEgo(*ownPos).length();
        }
        else
        {
            mc.motion.translation = 0;
            long int time = (wm->getTime() - startTime);

            if (time > 1000000000)
            {
                if (avgTime == 0)
                {
                    avgTime = time;
                }
                avgTime = (avgTime + time) / 2.0;
                cout << "[DriveToPost]    Time : " << time / 1000000000.0 << endl;
                cout << "[DriveToPost] AvgTime : " << avgTime / 1000000000.0 << endl;
            }

            // change target to other post side
            if (driveToPost == 1)
            {
                driveToPost--;
            }
            else
            {
                driveToPost++;
            }
            startTime = -1;
        }
        //cout << "[DriveToPost] translation: " << mc.motion.translation << endl;
        send(mc);
        /*PROTECTED REGION END*/
    }
    void DriveToPost::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1464189819779) ENABLED START*/ //Add additional options here
        /*PROTECTED REGION END*/
    }
/*PROTECTED REGION ID(methods1464189819779) ENABLED START*/ //Add additional methods here
/*PROTECTED REGION END*/
} /* namespace alica */
