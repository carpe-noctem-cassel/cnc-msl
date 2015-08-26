/*
 * $Id: ParticleFilter.cpp 2865 2007-12-16 21:24:50Z cn $
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
#include "../include/msl_localization.h"

#include "RandomHelper.h"
#include "EgoMotionEstimator.h"

#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <fstream>

#define DISTNONE 20000.0
#define SIGMA 20

using namespace msl_sensor_msgs;
using namespace msl_msgs;
using namespace std;

msl_localization::msl_localization(int nParticles_) {
	printf("ParticleFilter Constructor!\n");
	yellowGoalDirection = -1;
	nParticles = nParticles_;
	particles = NULL;	

	
	rawUpdatedPosition.x = 0.0;
	rawUpdatedPosition.y = 0.0;
	rawUpdatedPosition.heading = 0;

	for(int i = 0; i < RAWODOBUFSIZE; i++){
		positionBuffer[i] = rawUpdatedPosition;
		timestampBuffer[i] = 0;
	}

	integrationIndex = 0;
	bufferInitialized = false;
	msgid = 0;	

	yellowGoalDirection = 0;
	initParticles();

	LocalizationSuccess = 0.80;
	LinePointSigma = 15.0;
	UseRepParticles = false;

	initCounter = 0;
    coi.certainty = (-1);
    gaussHelper = new RandomGaussHelper();
	useOdometry=true;
	reinit = true;
	minimizationSteps = 12;
	mh = MapHelper::getInstance();
	minimize = mh->gradientAvailable();

}


msl_localization::~msl_localization(){
	cleanup();
}


void inline msl_localization::normalizeAngle(double &ang)
{
	if(ang > M_PI)
		ang -= 2.0*M_PI;
	else if(ang < -M_PI)
		ang += 2.0*M_PI;
}


void msl_localization::iterate(msl_sensor_msgs::LinePointListPtr & linePoints, unsigned char* distanceMap){
	printf("----------------------------------------------------\n");


	msl_actuator_msgs::RawOdometryInfo odomotryInfo;

	if(useOdometry) {
		odomotryInfo = *RosMsgReceiver::getInstance()->getOdometryInfo();
	}
	
	//Compute RawOdo Delta
	Position updatePos;
	updatePos.x = odomotryInfo.position.x - oldOdometryInfo.position.x;
	updatePos.y = odomotryInfo.position.y - oldOdometryInfo.position.y;
	updatePos.heading = odomotryInfo.position.angle - oldOdometryInfo.position.angle;
	normalizeAngle(updatePos.heading);

	updateParticles(updatePos.x, updatePos.y, updatePos.heading);

	printf("Update Vector: %f %f %f\n", updatePos.x, updatePos.y, updatePos.heading);

	//Compute Max Weight/index before weightupdate
	int maxIndPre = 0;
	double maxWeightPre = particles[0].weight;
	for(int i = 1; i < nParticles; i++){
		if(particles[i].weight > maxWeightPre){
			maxIndPre = i;
			maxWeightPre = particles[i].weight;
		}
	}
	printf("MaxParticle After MotionUpdate: %f %f %f\n", particles[maxIndPre].posx, particles[maxIndPre].posy, particles[maxIndPre].heading);

	unsigned char * linePointsInvalidity = (unsigned char *) malloc(linePoints->linePoints.size());
	memset((void *) linePointsInvalidity, 0, linePoints->linePoints.size());

	std::vector<Point2dInfo>::const_iterator first, last = linePoints->linePoints.end();
	//int invCounter = 0;

	//Move particles according to rawUpdatedPosition
	double posConfidence = 0.0;
	for(int i = 0; i < nParticles; i++){

		double dx = particles[i].posx - rawUpdatedPosition.x;
		double dy = particles[i].posy - rawUpdatedPosition.y;
		if(sqrt(dx*dx + dy*dy) < 0.25 && particles[i].weight > posConfidence){
			posConfidence = particles[i].weight;
		}

	}

	int compassValue = 0;

	unsigned char * LineLookup = distanceMap;

	double t = 0.9999;
	double h = (linePoints->linePoints.size())*1.0;
	double pv = pow((t/(1-t)),(1/h))/(1 + pow((t/(1-t)),(1/h)));

	int IHEIGHT = MapHelper::getInstance()->HEIGHT;
	int IWIDTH  = MapHelper::getInstance()->WIDTH;
	int IHEIGHT_2 = IHEIGHT/2;
	int IWIDTH_2 = IWIDTH/2;
	
	double resolution_1 = MapHelper::getInstance()->RESOLUTION;
	double FIELDHEIGHT = IHEIGHT*resolution_1;
	double FIELDWIDTH = IWIDTH*resolution_1;

	int maxPosLinePoints = 0;
	int maxNegLinePoints = 0;
	double maxWeight = 0.0;

	std::vector<unsigned char> linePointDistances;
	linePointDistances.clear();

	double * linePointsEgoDistances = (double *) malloc(linePoints->linePoints.size()*sizeof(double));
	double * linePointsEgoAngles = (double *) malloc(linePoints->linePoints.size()*sizeof(double));

	//Compute Ego LinePoint distance and Angle
	for(unsigned int i = 0; i < linePoints->linePoints.size(); i++){
		double distance = sqrt(linePoints->linePoints[i].x*linePoints->linePoints[i].x + linePoints->linePoints[i].y*linePoints->linePoints[i].y);

		linePointsEgoDistances[i] = distance;
		linePointsEgoAngles[i] = atan2(linePoints->linePoints[i].y, linePoints->linePoints[i].x);

		//???
		double compare_distance = (LinePointSigma + (distance - 0.40)*5.0); 
		int int_c_dist = lrint(compare_distance);
		if(int_c_dist < 0)
			int_c_dist = 0;
		if(int_c_dist > 255)
			int_c_dist = 255;

		unsigned char c = (unsigned char) int_c_dist;

		linePointDistances.push_back(c);
	}

	//Compute compassheading start
	double degrees = (((double) compassValue) / 10.0)*2.0*M_PI/360.0;

	double compX = cos(-degrees);
	double compY = sin(-degrees);

	/*double goalDegrees = (((double) yellowGoalDirection) / 10.0)*2.0*M_PI/360.0;
	double goalX = cos(-goalDegrees);
	double goalY = sin(-goalDegrees);
	
	// Is this the same as: compassHeading = goalDegrees - degrees; ?
	double compassHeading = atan2(compY, compX) - atan2(goalY, goalX);
	normalizeAngle(compassHeading);
	//Compute compassheading end
	*/
	ofstream lsfs("ErrorLandscape.txt");

	for(int i = 0; i < nParticles; i++){
		//ego2allow of linePoints

		int posLinePoints = 0;
		int negLinePoints = 0;

		double cos_;// = cos(particles[i].heading);
		double sin_;// = sin(particles[i].heading);
		double realx = 0.0;
		double realy = 0.0;

		double weight = 0.5;
		unsigned char dist = 0;
		double inp = 0.0;

		//Do not Consider Particles with an angle difference to compass < pi/3
		/*if(yellowGoalDirection >= 0 && compassValue >= 0){
			double diffHeading = compassHeading - particles[i].heading;
			
			normalizeAngle(diffHeading);

			if(fabs(diffHeading) > M_PI/3.0){
				weight = 0.1;
				if(i == nParticles-2)
					printf("Loc1 : Drop UpdatedPosition\n");
				if(i == nParticles-1)
					printf("Loc1 : Drop MaxParticle %d %f %f, %f %f %f\n", compassValue, degrees, particles[i].heading, particles[i].posx, particles[i].posy, particles[i].weight);
			}

		}*/

		std::vector<Point2dInfo>::const_iterator first, last = linePoints->linePoints.end();
		std::vector<unsigned char>::const_iterator firstDist, lastDist = linePointDistances.end();

		//If Particle has not been thrown away
		if(weight > 0.1) {

			int invIndex = 0;
			int tribotWeight = 0;
			float dx=0;
			float dy=0;
			float dangle=0;
			int validCount = 0;
			cos_ = cos(particles[i].heading);
			sin_ = sin(particles[i].heading);
			Rprop xUpdate(0.02); //4cm
			Rprop yUpdate(0.02);
			Rprop angleUpdate(0.05); //0.1 Rad
			float csquare = 2.50*2.50, ef, derrddist, distance;
						
			//Perform Gradient decent
			for(int m=0; m<minimizationSteps; m++) {
				dx=0;
				dy=0;
				dangle=0;
				validCount = 0;
				tribotWeight = 0;
				int n=0;
				double distsum = 0;

				for(first = linePoints->linePoints.begin(), firstDist = linePointDistances.begin(), n=0; first != last; ++first, ++firstDist, ++n) {
					if(linePointsInvalidity[invIndex] == 0) {
						//Irgendwo hier oder bei der Maperstellung is ein Fehler!
						//Transform LinePoint in coordinate system of current particle
						realx = particles[i].posx + cos_*(first->x) - sin_*(first->y);
						realy = particles[i].posy + sin_*(first->x) + cos_*(first->y);
			
						//Compute index in distance lookup
						int indX = lrint(realx/resolution_1) + IHEIGHT_2;
						int indY = lrint(-realy/resolution_1) + IWIDTH_2;
						//if(m==0 && i==0)cout << n << "\t" << first->x << "\t" << first->y << "\t" <<  indX << "\t" << indY << endl;
						
						//char approach
						//dx += mh->xGradient(indX, indY);
						//dy += mh->yGradient(indX, indY);
						//dangle += mh->angleGradient(indX, indY, particles[i].heading, first->y, first->x);
						
						//float approach
						distance = mh->getDistance(indX, indY);
						distsum = abs(distance);
						ef = csquare + distance * distance;
				      	derrddist = (2 * csquare * distance) /(ef * ef);
				      	dx += derrddist * mh->fxGradient(indX, indY);
				      	dy += derrddist * mh->fyGradient(indX, indY);
				      	dangle += derrddist * mh->fangleGradient(indX, indY, particles[i].heading, first->y, first->x);
						
						indX = lrint(-realy/resolution_1) + IHEIGHT_2;
						indY = lrint(realx/resolution_1) + IWIDTH_2;
						
						//Compute "Distance value" [0-254]
						if(indX >= 0 && indX < IHEIGHT && indY >= 0 && indY < IWIDTH){
							dist = LineLookup[indX*IWIDTH + indY];
						}
						else dist = 255;
						
						//Count linepoints within a certain range	
						if(dist<=555) { 
							tribotWeight += dist;//pow(dist, 0.75);
							validCount++;
						}
					}
				}
				
				
				weight = 1.0 - (tribotWeight)/((validCount)*510.0);
				//std::cout << dx << "\t" << dy << "\t" << dangle << std::endl;
				lsfs << particles[i].posx <<  "\t";
				lsfs << particles[i].posy <<  "\t";
				lsfs << particles[i].heading <<  "\t";
				lsfs << dx << "\t";
				lsfs << dy << "\t";
				lsfs << dangle << "\t";
				lsfs << weight << "\t";
				lsfs << distsum << "\t";
				lsfs << endl;
				particles[i].posx += xUpdate.getdW(dx);
				particles[i].posy += yUpdate.getdW(dy);
				//particles[i].heading += angleUpdate.getdW(dangle);
				cos_ = cos(particles[i].heading);
				sin_ = sin(particles[i].heading);
			}
			lsfs << endl;
			lsfs << endl;
			
			validCount = 0;
			tribotWeight = 0;
			//Iterate over Linepoints
			for(first = linePoints->linePoints.begin(), firstDist = linePointDistances.begin(); first != last; ++first, ++firstDist) {
				if(linePointsInvalidity[invIndex] == 0){
					//Transform LinePoint in coordinate system of current particle
					realx = particles[i].posx + cos_*(first->x) - sin_*(first->y);
					realy = particles[i].posy + sin_*(first->x) + cos_*(first->y);
		
					//Compute index in distance lookup
					int indX = lrint(-realy/resolution_1) + IHEIGHT_2;
					int indY = lrint(realx/resolution_1) + IWIDTH_2;
		
					//Compute "Distance value" [0-254]
					if(indX >= 0 && indX < IHEIGHT && indY >= 0 && indY < IWIDTH){
						dist = LineLookup[indX*IWIDTH + indY];
					}
					else dist = 255;
					
					//Count linepoints within a certain range	
					if(dist<=555) { 
						tribotWeight += dist;//pow(dist, 0.75);
						validCount++;
					}
					//weight = weight*inp/((1-weight)*(1-inp) + weight*inp);
				}
				invIndex++;
			}
			if((linePoints->linePoints.size())>0 && validCount>0)
		//	  weight = 1.0 - tribotWeight/((linePoints->linePoints.size() - invCounter)*510.0);
			  weight = 1.0 - (tribotWeight)/((validCount)*510.0);
			else
			  weight = 0.1;
		}

		particles[i].weight = weight;
		if(weight > maxWeight) {
			maxWeight = weight;
		}
	}
	lsfs.close();

	//Compute Best Particle + Index
	int maxInd = 1;
	maxWeight = 0;//particles[0].weight;
	for(int i = 1; i < nParticles; i++){
		if(particles[i].weight > maxWeight){
			maxInd = i;
			maxWeight = particles[i].weight;
		}
	}
	//Change best particle only if it is realy better!	 
	/*if((maxWeight-0.2)<(particles[0].weight)) {
			maxInd = 0;
			maxWeight = particles[0].weight;
	}*/

	printf("ParticleFilter: posX: %f posY: %f heading %f prop: %f\n", particles[maxInd].posx, particles[maxInd].posy, particles[maxInd].heading, particles[maxInd].weight);
	memcpy(&maxParticle, &(particles[maxInd]), sizeof(Particle));

	//Update rawUpdatedPosition;
	//Position rawPosition = rawOdometryHelper->getPositionData();
	
	double rotAngle = rawUpdatedPosition.heading - odomotryInfo.position.angle;
	normalizeAngle(rotAngle);

	double deltaX = cos(rotAngle)*updatePos.x - sin(rotAngle)*updatePos.y;
	double deltaY = sin(rotAngle)*updatePos.x + cos(rotAngle)*updatePos.y;

	if(!reinit) {
		rawUpdatedPosition.x += deltaX;
		rawUpdatedPosition.y += deltaY;
		rawUpdatedPosition.heading += updatePos.heading;
		normalizeAngle(rawUpdatedPosition.heading);
	}

	bool jump = false;

	//After 0 Iterations, Successfull Lokalization for at least 75 linepoints
	if(reinit || (initCounter >= 0 && maxParticle.weight > LocalizationSuccess && linePoints->linePoints.size() > 75)){
		bool updateAllowed = true;

		//If Position is within a corner
		/*if(fabs(rawUpdatedPosition.x) > FootballField::FieldLength/2.0 - FootballField::GoalAreaWidth && 
				fabs(rawUpdatedPosition.y) > FootballField::GoalAreaLength/2.0){

			double diffX = maxParticle.posx - rawUpdatedPosition.x;
			double diffY = maxParticle.posy - rawUpdatedPosition.y;

			//No Update if difference between rawUpdatedPosition and maxParticle > 300
			if(sqrt(diffX*diffX + diffY*diffY) > 300.0)
				updateAllowed = false;
		}*/

		double rawMaxWeight = 0.0;
		int maxTrackedIndex = nParticles - 1;

		for(int i = 0; i < nParticles; i++){
			double diffX = particles[i].posx - rawUpdatedPosition.x;
			double diffY = particles[i].posy - rawUpdatedPosition.y;

			//Compute Max particleweight within 50mm to rawUpdatesPosition
			if(sqrt(diffX*diffX + diffY*diffY) < 0.05){
				if(particles[i].weight > rawMaxWeight){
					rawMaxWeight = particles[i].weight;
					maxTrackedIndex = i;
				}
			}
		}

		//Update always allowed if weights < 0.4
		if(rawMaxWeight < 0.4)
			updateAllowed = true;
		
		double estimatedPositionWeight = particles[nParticles-2].weight;

		if(updateAllowed || reinit){
			//Compute distance and angle difference beteween rawUpdatedPosition and Maxparticle
			double headingDiff = fabs(maxParticle.heading - rawUpdatedPosition.heading);
			if(headingDiff > M_PI){
				headingDiff -= 2.0*M_PI;
			}
		
			if(fabs(headingDiff) > M_PI/360.0){
				rawUpdatedPosition.heading = maxParticle.heading;
			}

			double dist = sqrt((maxParticle.posx - rawUpdatedPosition.x)*(maxParticle.posx - rawUpdatedPosition.x) + (maxParticle.posy - rawUpdatedPosition.y)*(maxParticle.posy - rawUpdatedPosition.y)); 

			//Update rawUpdatePosition to best particle within 50mm
			rawUpdatedPosition.x = particles[maxTrackedIndex].posx;
			rawUpdatedPosition.y = particles[maxTrackedIndex].posy;

			//Believe more in the current position than positions > 5cm away
			double jumpThres = 0.02;
			if(estimatedPositionWeight > 0.98)
				jumpThres = 0.005;
			if(estimatedPositionWeight > 0.99)
				jumpThres = 0.001;

			//Update rawUpdatedPosition only farer away than 300mm if confidence is > estimatedPositionWeight + jumpthres
			if(dist > 0.3 && maxParticle.weight - estimatedPositionWeight >= jumpThres){
				rawUpdatedPosition.x = maxParticle.posx;
				rawUpdatedPosition.y = maxParticle.posy;
				rawUpdatedPosition.heading = maxParticle.heading;
				timestampBuffer[integrationIndex] = 0;
				jump = true;
			}
		}
	}

	//Write rawupdated Position + timestamp in ringbuffer
	if(bufferInitialized){
		integrationIndex++;
		if(integrationIndex >= RAWODOBUFSIZE)
			integrationIndex -= RAWODOBUFSIZE;

	}
	else {
		bufferInitialized = true;
	}

	positionBuffer[integrationIndex] = rawUpdatedPosition;
 	timestampBuffer[integrationIndex] = ros::Time::now().nsec*1000000000+ros::Time::now().nsec;

	//Update Current Position and Velocity Estimation by Egomotionestimator
	EgoMotionEstimator * estimator = EgoMotionEstimator::getInstance();
	mrOld = mr;
	mr = estimator->trackObject(positionBuffer, timestampBuffer, RAWODOBUFSIZE, integrationIndex, 0.4E07);

	//If position or velocity jumped or if Velocity is very small -> Use old Velocity Estimation
	if(reinit || jump || (fabs(sqrt(mr.velocity.vx*mr.velocity.vx + mr.velocity.vy*mr.velocity.vy) - sqrt(mrOld.velocity.vx*mrOld.velocity.vx + mrOld.velocity.vy*mrOld.velocity.vy)) > 400.0 && sqrt(mr.velocity.vx*mr.velocity.vx + mr.velocity.vy*mr.velocity.vy) < 1.0E-32)) {
		reinit=false;
		mr.velocity = mrOld.velocity;
	}

	int logTime = (int) ros::Time::now().nsec*1000000000+ros::Time::now().nsec;;

	printf("Estimated Velocity %f\t %f\t %f\t %f\t %d\n", mr.velocity.vx, mr.velocity.vy, sqrt(mr.velocity.vx*mr.velocity.vx + mr.velocity.vy*mr.velocity.vy), mr.velocity.w, logTime);
	printf("Estimated Position %f\t %f\t %f\n", mr.position.x, mr.position.y, mr.position.heading);

	//Send Odometry
	Position rawUpdatedPositionNew = rawUpdatedPosition;

	PositionInfo robotPosition;
	MotionInfo robotVelocity;
	
	robotPosition.x = (mr.position.x);
	robotPosition.y = (mr.position.y);
	robotPosition.angle = (mr.position.heading);

	//Auskommentieren, wenn Delay zu groß! 
	rawUpdatedPositionNew.x = mr.position.x;
	rawUpdatedPositionNew.y = mr.position.y;
	rawUpdatedPositionNew.heading = mr.position.heading;
	unsigned long long timestamp = ros::Time::now().nsec*1000000000+ros::Time::now().nsec;

	robotVelocity.translation = (sqrt(mr.velocity.vx*mr.velocity.vx + mr.velocity.vy*mr.velocity.vy));
	robotVelocity.rotation = (mr.velocity.w);
	robotVelocity.angle = (atan2(mr.velocity.vy, mr.velocity.vx));

	coi.position = (robotPosition);
	coi.motion = (robotVelocity);
	//coi.certainty = (calculateWeightForEstimatedPosition(rawUpdatedPositionNew, linePoints, lineDistHelper, linePointsInvalidity, invCounter));
	coi.certainty = (calculateWeightForEstimatedPosition(rawUpdatedPositionNew, linePoints, distanceMap, linePointsInvalidity, 0));
	coi.locType.type = (LocalizationType::ParticleFilter);

	printf("MaxParticle Confidence %f\n", coi.certainty);		
	oldOdometryInfo = odomotryInfo;
	writeCoi();

	if(particles[nParticles - 1].weight < 0.5)
		printf("Loc1: Previous MaxParticle with low confidence\n");
	if(particles[nParticles - 2].weight < 0.5)
		printf("Loc1: Previous RawUpdatedPos with low confidence\n");
	
	resample(*gaussHelper);

	if(maxParticle.weight < LocalizationSuccess){
		printf("Something going wrong with Localization!\n");
		printf("Cannot match Line Points!\n");
	}

	initCounter++;
	if(initCounter > 10000)
		initCounter = 10000;

	free(linePointsInvalidity);
	free(linePointsEgoDistances);
	free(linePointsEgoAngles);
}


void msl_localization::sendParticleCloud() {
	geometry_msgs::PoseArray msg;
	msg.header.stamp = ros::Time::now();
	msg.header.frame_id = "/map";
	
	geometry_msgs::Pose p;
	p.position.z = 0;
	
	tf::Quaternion q;
	for(int i = 0; i < nParticles; i++){
		p.position.x = particles[i].posx;
		p.position.y = particles[i].posy;
		q = tf::createQuaternionFromYaw(particles[i].heading);
		p.orientation.z = q.getZ();
		p.orientation.w = q.getW();
		msg.poses.push_back(p);
	}
	
	RosMsgReceiver::getInstance()->sendParticleCloud(msg);
}


void msl_localization::initParticles(){
	particles = (Particle *) malloc(nParticles*sizeof(Particle));

	RandomHelper::initRandom();
	double maxX = MapHelper::getInstance()->HEIGHT/2.0;
	double maxY = MapHelper::getInstance()->WIDTH/2.0;
	double maxAngle = M_PI;
	initParticles(0,0,0, maxX, maxY, maxAngle);
}


void msl_localization::initParticles(double x, double y, double angle, double maxX, double maxY, double maxAngle) {
	std::cout << "Moving Particle Cloud to: X:\t" << x << "\ty\t" << y << "\theading\t" << angle << std::endl;
	maxParticle.posx = x;
	maxParticle.posy = y;
	maxParticle.heading = angle;
	maxParticle.weight = 0.0;
	
	rawUpdatedPosition.x = x;
	rawUpdatedPosition.y = y;
	rawUpdatedPosition.heading = angle;
	
	reinit=true;
	
	for(int i = 0; i < RAWODOBUFSIZE; i++){
		positionBuffer[i] = rawUpdatedPosition;
		timestampBuffer[i] = 0;
	}
	timestampBuffer[0]=ros::Time::now().nsec*1000000000+ros::Time::now().nsec;
	
	for(int i = 0; i < nParticles; i++){
		particles[i].posx = x+(RandomHelper::rand01() - 0.5)*2.0*maxX;
		particles[i].posy = y+(RandomHelper::rand01() - 0.5)*2.0*maxY;
		particles[i].heading = angle+(RandomHelper::rand01() - 0.5)*2.0*maxAngle;
		particles[i].weight = 0.5;
	}
	coi.certainty = (-1);
	
	//Last two Particles are MaxParticle and rawUpdatesPosition			
	particles[nParticles-1].posx = x;
	particles[nParticles-1].posy = y;
	particles[nParticles-1].heading = angle;
	particles[nParticles-1].weight = maxParticle.weight;

	particles[nParticles-2].posx = x;
	particles[nParticles-2].posy = y;
	particles[nParticles-2].heading = angle;
	particles[nParticles-2].weight = maxParticle.weight;
	
	integrationIndex = 0;
	msgid = 0;	
	initCounter = 0;
    coi.certainty = (-1);
}

		
void msl_localization::resample(RandomGaussHelper & gaussHelper){
	int distX = MapHelper::getInstance()->maxXLocation - MapHelper::getInstance()->minXLocation;
	int distY = MapHelper::getInstance()->maxYLocation - MapHelper::getInstance()->minYLocation;
	double midX = ((MapHelper::getInstance()->minXLocation-MapHelper::getInstance()->WIDTH/2)+(distX/2))*MapHelper::getInstance()->RESOLUTION;
	double midY = ((MapHelper::getInstance()->minYLocation-MapHelper::getInstance()->HEIGHT/2)+(distY/2))*MapHelper::getInstance()->RESOLUTION;
	double maxX = (distX*MapHelper::getInstance()->RESOLUTION)/2.0;
	double maxY = (distY*MapHelper::getInstance()->RESOLUTION)/2.0;
	double maxAngle = M_PI;

	Particle repParticles[nParticles];
	unsigned int nRepParticles = 0;

	double distThreshold = -1.0;
	//if(UseRepParticles || isGoalie)
	if(UseRepParticles)
		distThreshold = 0.05*0.05;

	if(distThreshold < 0.0){
		//Count and store representative particles (weight > 0.9)
		for(int i = 0; i < nParticles; i++){
			if(particles[i].weight > 0.9){ //Was before 0.9
				repParticles[nRepParticles] = particles[i];
				nRepParticles++;
			}
		}
	}
	else {
		for(int i = 0; i < nParticles; i++){
			if(particles[i].weight > 0.8){
				bool repFound = false;
				//?????????????????????????????? WTF
				for(unsigned int j = 0; j < nRepParticles; j++){
					double distance = (repParticles[j].posx - particles[i].posx)*(repParticles[j].posx - particles[i].posx) + 
								(repParticles[j].posy - particles[i].posy)*(repParticles[j].posy - particles[i].posy);
	
					if(distance < distThreshold){
						repFound = true;
						if(particles[i].weight > repParticles[j].weight){
							repParticles[j] = particles[i];
							break;
						}
					}
				}
				if(!repFound){
					repParticles[nRepParticles] = particles[i];
					nRepParticles++;
				}
			}
		}
	}

	Particle * tmpParticles = (Particle *) malloc(nParticles*sizeof(Particle));
	memcpy(tmpParticles, particles, nParticles*sizeof(Particle));
	bool globalRelocalization = false;
	bool found = (nRepParticles > 0) || !globalRelocalization;
	double * cumWeights = (double *) malloc(nRepParticles*sizeof(double));
	double sum = 0.0;

	//Compute cumlative weight + normalization factor
	for(unsigned int i = 0; i < nRepParticles; i++){
		sum += repParticles[i].weight;		
		cumWeights[i] = sum;
	}
	//Normalize Weights
	for(unsigned int i = 0; i < nRepParticles; i++)	cumWeights[i] /= sum;

	int nResample = 0;
	printf("Number RepParticles: %d\n", nRepParticles);

	//Mutate Max 400 Particles
	if(found){
		//nResample = (nParticles*2)/3;
		//if(nResample > 400)
		//	nResample = 400;
		nResample = nParticles;
	}
	

	//Resample first 800
	for(int i = 0; i < nParticles - nResample; i++){
		particles[i].posx = midX + (RandomHelper::rand01() - 0.5)*2.0*maxX;
		particles[i].posy = midY + (RandomHelper::rand01() - 0.5)*2.0*maxY;
		particles[i].heading = (RandomHelper::rand01() - 0.5)*2.0*maxAngle;
		particles[i].weight = 0.5;		
	}

	//Mutation of last 400
	for(int i = nParticles - nResample; i < nParticles; i++){
		double p = RandomHelper::rand01();
		unsigned int ind = 0;

		while(cumWeights[ind] < p && ind < nRepParticles)
			ind++;

		//ind = i;//p * (nParticles - nResample) + i;
		
		if (ind >= nParticles)
			ind = nParticles -1;

		double sigma = (-2.0*repParticles[ind].weight + 2);
		if(sigma < 0.01) //0.01
			sigma = 0.01;
		particles[i].posx = repParticles[ind].posx + gaussHelper.getRandomGauss()*0.5*sigma;
		particles[i].posy = repParticles[ind].posy + gaussHelper.getRandomGauss()*0.5*sigma;
		particles[i].heading = repParticles[ind].heading + gaussHelper.getRandomGauss()*sigma*M_PI/4.0;
		particles[i].weight = 0.5;
	}

	//Last two Particles are MaxParticle and rawUpdatesPosition			
	particles[nParticles-1].posx = maxParticle.posx;
	particles[nParticles-1].posy = maxParticle.posy;
	particles[nParticles-1].heading = maxParticle.heading;
	particles[nParticles-1].weight = maxParticle.weight;

	particles[nParticles-2].posx = rawUpdatedPosition.x;
	particles[nParticles-2].posy = rawUpdatedPosition.y;
	particles[nParticles-2].heading = rawUpdatedPosition.heading;
	particles[nParticles-2].weight = maxParticle.weight;
	
	free(tmpParticles);
	free(cumWeights);
}


void msl_localization::updateParticles(double deltaX, double deltaY, double deltaH){
	//Move all Particles by RawOdometry
	if(!useOdometry) return;

	double odoAngle = 0;
	odoAngle = oldOdometryInfo.position.angle;
	
	for(int i = 0; i < nParticles; i++){
		double rotAngle = particles[i].heading - odoAngle;
		normalizeAngle(rotAngle);

		double newDeltaX = cos(rotAngle)*deltaX - sin(rotAngle)*deltaY;
		double newDeltaY = sin(rotAngle)*deltaX + cos(rotAngle)*deltaY;

		particles[i].posx += newDeltaX;
		particles[i].posy += newDeltaY;
		particles[i].heading += deltaH;
		normalizeAngle(particles[i].heading);
	}

	particles[0].posx = rawUpdatedPosition.x;
	particles[0].posy = rawUpdatedPosition.y;
	particles[0].heading = rawUpdatedPosition.heading;
	particles[0].weight = maxParticle.weight;

//	particles[1] = maxParticle;
}


void msl_localization::cleanup(){
	if(particles != NULL){
		free(particles);
	}
}

Particle msl_localization::getMaxParticle(){
	return maxParticle;
}

int msl_localization::getNumberParticles(){
	return nParticles;
}

Particle * msl_localization::getParticles(){
	return particles;
}

Particle msl_localization::getEstimatedPosition(){
	Particle wPos;
	wPos.posx = rawUpdatedPosition.x;
	wPos.posy = rawUpdatedPosition.y;
	wPos.heading = rawUpdatedPosition.heading;
	wPos.weight = coi.certainty;
	return wPos;
}


double msl_localization::calculateWeightForEstimatedPosition(Position pos, msl_sensor_msgs::LinePointListPtr & linePoints, unsigned char *distanceMap, unsigned char * linePointsInvalidity, int invCounter){
	unsigned char * LineLookup = distanceMap;

	double LinePointSigma = 15.0;
	double offset = 1500;
	double t = 0.9999;
	double h = (linePoints->linePoints.size() - invCounter)*1.0;
	double pv = pow((t/(1-t)),(1/h))/(1 + pow((t/(1-t)),(1/h)));
	
	int IHEIGHT = MapHelper::getInstance()->HEIGHT;
	int IWIDTH  = MapHelper::getInstance()->WIDTH;
	int IHEIGHT_2 = IHEIGHT/2;
	int IWIDTH_2 = IWIDTH/2;

	double resolution_1 = MapHelper::getInstance()->WIDTH;

	std::vector<Point2dInfo>::const_iterator first, last = linePoints->linePoints.end();

	int posLinePoints = 0;
	int negLinePoints = 0;
	double cos_ = cos(pos.heading);
	double sin_ = sin(pos.heading);
	double realx = 0.0;
	double realy = 0.0;

	double weight = 0.5;
	unsigned char dist = 0;
	double inp = 0.0;

	if(weight > 0.1) {
		int invIndex = 0;

		int tribotWeight = 0;

		for(first = linePoints->linePoints.begin(); first != last; ++first){
			double distance = sqrt((first->x)*(first->x) + (first->y)*(first->y));
		
			double compare_distance = (LinePointSigma + (distance - 400.0)*0.005); 
			int int_c_dist = lrint(compare_distance);
			if(int_c_dist < 0)
				int_c_dist = 0;
			if(int_c_dist > 255)
				int_c_dist = 255;
	
			unsigned char c = (unsigned char) int_c_dist;

			if(linePointsInvalidity[invIndex] == 0){
				realx = pos.x + cos_*(first->x) - sin_*(first->y);
				realy = pos.y + sin_*(first->x) + cos_*(first->y);
				
					int indX = lrint(-realy*resolution_1) + IHEIGHT_2;
					int indY = lrint(realx*resolution_1) + IWIDTH_2;
		
					if(indX >= 0 && indX < IHEIGHT && indY >= 0 && indY < IWIDTH){
						dist = LineLookup[indX*IWIDTH + indY];
					}
					else
						dist = 255;

					if(dist >= 254)
						dist = 254;

					double dist_real = dist/255.0;
					double new_dist_real = sqrt((250.0*250.0)/(1.0 - dist_real) - 250.0*250.0)/10.0;

					new_dist_real = lrint(new_dist_real);
					if(new_dist_real >= 255.0)
						new_dist_real = 255.0;

					unsigned char new_dist = (unsigned char) lrint(new_dist_real);

					if(new_dist < c){
						posLinePoints++;	
					}

					tribotWeight += dist;
					//weight = weight*inp/((1-weight)*(1-inp) + weight*inp);
				}
			invIndex++;
		}
		negLinePoints = linePoints->linePoints.size() - invCounter - posLinePoints;

		inp = pv;
		if(posLinePoints > 0)
			weight = 1.0/(1.0 + pow(1-inp, posLinePoints)*(1-weight)/(weight*pow(inp, posLinePoints)));

		inp = 1.0 - pv;
		if(negLinePoints > 0)
			weight = 1.0/(1.0 + pow(1-inp, negLinePoints)*(1-weight)/(weight*pow(inp, negLinePoints)));

		//Endy The Hero
		//weight = 1.0 - tribotWeight/((linePoints->linePoints.size() - invCounter)*510.0);
		if(invCounter==linePoints->linePoints.size() || linePoints->linePoints.size()==0) weight=0.1;
	}
	return weight;
}

void msl_localization::writeCoi()
{
	if (coi.certainty != -1 ) {
		unsigned long long timestamp = ros::Time::now().sec*1000000000ull+ros::Time::now().nsec;
		coi.timestamp = (timestamp);

		RosMsgReceiver::getInstance()->coipub.publish(coi);
	}
	else printf("NewLoc: OOOPS no coi in particlefilter");
}
