/*
 * DribbleRotateLeft.h
 *
 *  Created on: Jan 25, 2017
 *      Author: cn
 */

#ifndef AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEROTATELEFT_H_
#define AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEROTATELEFT_H_

#include "Plans/DribbleCalibration/Behaviours/Interfaces/ICalibration.h"
#include "Plans/DribbleCalibration/Container/MovementContainer.h"
#include "SystemConfig.h"

namespace alica
{
	class DribbleRotateLeft : public ICalibration
	{
	public:
		DribbleRotateLeft();
		virtual ~DribbleRotateLeft();

		MotionControl move(int trans);
		void writeConfigParameters();
		void readConfigParameters();
		void adaptParams();
		void resetParams();
		void saveParams();

	private:
		MovementContainer mCon;

		// parameters
		double epsilonRot;

		// calibration parameters
		double changingValue;
		double defaultValue;

		double rotationSpeed;

		// save parameters
		double maxValue;
		double minValue;
	};

} /* namespace alica */

#endif /* AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEROTATELEFT_H_ */
