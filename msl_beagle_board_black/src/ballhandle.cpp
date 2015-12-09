/*
 * ballhandle.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Lukas Will
 */


#include "ballhandle.h"

using namespace BlackLib;

	BallHandle::BallHandle(pwmName pwm_P, gpioName dir_P, gpioName reset_P, gpioName ff1_P, gpioName ff2_P) {
		pwm = new BlackPWM(pwm_P);
		dir = new BlackGPIO(dir_P, output, FastMode);
		reset = new BlackGPIO(reset_P, output, FastMode);
		ff1 = new BlackGPIO(ff1_P, input, FastMode);
		ff2 = new BlackGPIO(ff2_P, input, FastMode);


		pwm->setPeriodTime(period, nanosecond);
		pwm->setSpaceRatioTime(0, nanosecond);
		pwm->setRunState(run);

		dir->setValue(low);
		reset->setValue(high);
	}

	BallHandle::~BallHandle() {
		delete pwm;
		delete dir;
		delete reset;
		delete ff1;
		delete ff2;
	}

	void BallHandle::setBallHandling(int8_t value) {
		// value > 0 -> left
		// value < 0 -> right
		if ((value > 0) && (direction == static_cast<digitalValue>(right))) {
			direction_desired = static_cast<digitalValue>(left);
		}

		if ((value < 0) && (direction == static_cast<BlackLib::digitalValue>(left))) {
			direction_desired = static_cast<BlackLib::digitalValue>(right);
		}

		// Check that value is in range from -100 to 100
		if (value > 100) { value = 100; }
		if (value < -100) { value = -100; }
		speed_desired = abs(value) * period / 100;
	}

	void BallHandle::setTimeout() {
		// Deactivates the BallHandling when controlBallHandling() is called next time
		this->setBallHandling(0);
	}

	void BallHandle::controlBallHandling() {
		if (speed_desired == 0) {
			speed = 0;
			pwm->setSpaceRatioTime(speed, nanosecond);			// Time for this Operation: 900us
		} else {
			if (direction != direction_desired) {
				direction = direction_desired;
				speed = 0;
				pwm->setSpaceRatioTime(speed, nanosecond);		// Time for this Operation: 900us
				dir->setValue(direction);						// Time for this Operation: 550us
			}

			if (speed != speed_desired) {
				speed = speed_desired;
				pwm->setSpaceRatioTime(speed, nanosecond);		// Time for this Operation: 900us
			}
		}
	}

	uint8_t BallHandle::getError() {
		uint8_t ff = (ff1->getNumericValue() << 1) | ff2->getNumericValue();

		return ff;
	}

