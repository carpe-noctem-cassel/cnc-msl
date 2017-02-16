/*
 * DribbleBackward.h
 *
 *  Created on: Jan 6, 2017
 *      Author: cn
 */

#ifndef AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEBACKWARD_H_
#define AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEBACKWARD_H_

#include <Plans/DribbleCalibration/Behaviours/Interfaces/ICalibration.h>
#include <Plans/DribbleCalibration/Container/MovementContainer.h>
#include <memory>

namespace alica
{
	class DribbleBackward : public ICalibration
	{
	public:
		DribbleBackward();
		virtual ~DribbleBackward();
		shared_ptr<DribbleCalibrationQuery> move(int trans);
		void writeConfigParameters();
		void readConfigParameters();
		void adaptParams();
		void resetParams();
		void saveParams();

	private:
		MovementContainer mCon;

		// parameters
		double epsilonT;

		// calibration parameters
		double changingValue;
		double defaultValue;

		// save parameters
		double maxValue;
		double minValue;

		// ball handling
		double actuatorSpeed;
	};
}
#endif /* AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEBACKWARD_H_ */