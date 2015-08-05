/*
 * $Id: ParticleFilter.h 2863 2007-12-16 20:26:19Z rreichle $
 *
 *
 * Copyright 2005,2006 Carpe Noctem, Distributed Systems Group,
 * University of Kassel. All right reserved.
 *
 * The code is derived from the software contributed to Carpe Noctem by
 * the Carpe Noctem Team.
 *
 * The code is licensed under the Carpe Noctem Userfriendly BSD-Based
 * License (CNUBBL). Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided that the
 * conditions of the CNUBBL are met.
 *
 * You should have received a copy of the CNUBBL along with this
 * software. The license is also available on our website:
 * http://carpenoctem.das-lab.net/license.txt
 *
 *
 * <description>
 */
#ifndef ParticleFilter_H
#define ParticleFilter_H

#include "RandomHelper.h"
#include "Types.h"
#include <vector>
#include "MapHelper.h"
#include <tf/transform_listener.h>
#include <CNSensorMsgs/CorrectedOdometryInfo.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include "Rprop.h"


#define RAWODOBUFSIZE 100


class ParticleFilter {

	public:
		ParticleFilter(int nParticles_);
		~ParticleFilter();

		void iterate(std::vector<LinePoint> & linePoints, unsigned char* distanceMap);
		void updateParticles(double deltaX, double deltaY, double deltaH); 
		Particle getMaxParticle();

		int getNumberParticles();
		Particle * getParticles();

		Particle getEstimatedPosition();
		
		static double calculateWeightForEstimatedPosition(Position pos, std::vector<LinePoint> & linePoints, unsigned char *distanceMap, unsigned char * linePointsInvalidity, int invCounter);
		void writeCoi();
		
		void sendParticleCloud();
		void initParticles(double x, double y, double angle, double maxX, double maxY, double maxAngle);

	protected:
		bool useOdometry;
		int minimizationSteps;
		bool minimize;
		RandomGaussHelper* gaussHelper;
		tf::TransformListener listener;
		tf::StampedTransform oldTransform;

		CNSensorMsgs::CorrectedOdometryInfo coi;

		int nParticles;
		void initParticles();
		void resample(RandomGaussHelper & gaussHelper);
		void cleanup();
		void normalizeAngle(double &ang);

		Particle * particles;
		Particle maxParticle;

		Position rawUpdatedPosition;
		unsigned short msgid;
		
		bool isGoalie;

		double LocalizationSuccess;
		double LinePointSigma;
		bool UseRepParticles;
		bool UseBlueGoal;
		bool UseCornerPosts;
		
		int yellowGoalDirection;

		Position positionBuffer[RAWODOBUFSIZE];
		unsigned long long timestampBuffer[RAWODOBUFSIZE];

		int integrationIndex;
		bool bufferInitialized;
		bool reinit;

		MovingRobot mr;
		MovingRobot mrOld;

		int initCounter;
		tf::TransformBroadcaster tfBroadcaster;
		MapHelper *mh;
};


#endif
