/*
 * DribbleRotateRight.h
 *
 *  Created on: Jan 25, 2017
 *      Author: cn
 */

#ifndef AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEROTATERIGHT_H_
#define AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEROTATERIGHT_H_

#include <msl_robot/dribbleCalibration/behaviours/interfaces/ICalibration.h>
#include <msl_robot/dribbleCalibration/container/MovementContainer.h>
#include <memory>

namespace msl
{
	class DribbleRotateRight : public ICalibration
	{
	public:
		DribbleRotateRight();
		virtual ~DribbleRotateRight();

		shared_ptr<DribbleCalibrationQuery> move(int trans);
		void writeConfigParameters();
		void readConfigParameters();
		void adaptParams();
		void resetParams();
		void saveParams();

	private:
		MovementContainer mCon;
		shared_ptr<DribbleCalibrationQuery> query;

		// parameters
		double epsilonRot;

		// calibration parameters
		double changingValue;
		double defaultValue;

		double rotationSpeed;

		// save parameters
		double minValue;
		double maxValue;
	};

} /* namespace alica */

#endif /* AUTOGENERATED_SRC_PLANS_DRIBBLECALIBRATION_BEHAVIOURS_CALIBRATIONS_DRIBBLEROTATERIGHT_H_ */