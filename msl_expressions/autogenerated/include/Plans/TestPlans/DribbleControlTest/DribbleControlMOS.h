#ifndef DribbleControlMOS_H_
#define DribbleControlMOS_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1479905178049) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica {
class DribbleControlMOS: public DomainBehaviour {
public:
	DribbleControlMOS();
	virtual ~DribbleControlMOS();
	virtual void run(void* msg);
	/*PROTECTED REGION ID(pub1479905178049) ENABLED START*/ //Add additional public methods here
	/*PROTECTED REGION END*/
protected:
	virtual void initialiseParameters();
	/*PROTECTED REGION ID(pro1479905178049) ENABLED START*/ //Add additional protected methods here
	/*PROTECTED REGION END*/
private:
	/*PROTECTED REGION ID(prv1479905178049) ENABLED START*/ //Add additional private methods here
	double getBallVelocity(double velX, double velY);
	double getBallAngle(double velX, double velY);
	double getLeftArmVelocity(double ballVelocity, double ballAngle);
	double getRightArmVelocity(double ballVelocity, double ballAngle);
	void getBallPath(double translation, double angle, double rotation,
			double &velX, double &velY);

	int sign(double x);

	int testBehaviour;
	int testSpeed;
	double testRot;
	double testAngle;
	int testCount;
	int testCount2;

	double speedNoBall;

	double dkFactor;
	double translationOld;
	double rotationOld;
	double angleOld;

	// to increase initial actuator speed
	double powerFactor;
	double transTolerance;
	double rotTolerance;
	double angleTolerance;

	bool testingMode;

	double velToInput;
	double staticUpperBound;
	double staticMiddleBound;
	double staticLowerBound;
	double staticNegVelX;
	double epsilonT;
	double epsilonY;
	double epsilonRot;
	double rBallRobot;
	double forwConst;
	double sidewConst;
	double diagConst;
	double phi;
	double velYFactor;

	supplementary::SystemConfig* sc;

	/*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* DribbleControlMOS_H_ */
