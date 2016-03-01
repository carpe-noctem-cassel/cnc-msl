/*
 * AlloSearchArea.cpp
 *
 *  Created on: Feb 4, 2016
 *      Author: Stefan Jakob
 */

#include "robotmovement/AlloSearchArea.h"

namespace msl
{

	shared_ptr<vector<shared_ptr<AlloSearchArea>>> AlloSearchArea::daList = make_shared<vector<shared_ptr<AlloSearchArea>>>(500);

	AlloSearchArea::AlloSearchArea() :
			SearchArea()
	{

	}

	AlloSearchArea::~AlloSearchArea()
	{
	}

	shared_ptr<AlloSearchArea> AlloSearchArea::getAnArea(double langle, double hangle, double minDist, double maxDist,
															shared_ptr<geometry::CNPoint2D> center,
															shared_ptr<geometry::CNPosition> ownPos)
	{
		shared_ptr<AlloSearchArea> ret = daList->at(counter);
		counter = (counter +1) % maxNum;
		ret->langle = langle;
		ret->hangle = hangle;
		ret->minDist = minDist;
		ret->maxDist = maxDist;
		ret->center = center;
		ret->ownPos = ownPos;
		ret->midP->x = center->x;
		ret->midP->y = center->y;
		ret->midP->x += cos((hangle+langle)/2)*(maxDist+minDist)/2;
		ret->midP->y += sin((hangle+langle)/2)*(maxDist+minDist)/2;
		ret->val = 0;
		return ret;
	}

	shared_ptr<vector<shared_ptr<SearchArea> > > AlloSearchArea::expand()
	{
		shared_ptr<vector<shared_ptr<SearchArea>>> l = make_shared<vector<shared_ptr<SearchArea>>>(4);
		if (maxDist-minDist < 200)
		{
			return l;
		}
		shared_ptr<AlloSearchArea> tmp = getAnArea(langle,(hangle+langle)/2,minDist,(minDist+maxDist)/2,center,ownPos);
		if (tmp->isValid())
		{
			l->push_back(tmp);
		}
		//tmp = new SearchArea((hangle+langle)/2,hangle,minDist,(minDist+maxDist)/2,center,ownPos);
		tmp = getAnArea((hangle+langle)/2,hangle,minDist,(minDist+maxDist)/2,center,ownPos);
		if (tmp->isValid())
		{
			l->push_back(tmp);
		}
		//tmp = new SearchArea(langle,(hangle+langle)/2,(minDist+maxDist)/2,maxDist,center,ownPos);
		tmp = getAnArea(langle,(hangle+langle)/2,(minDist+maxDist)/2,maxDist,center,ownPos);
		if (tmp->isValid())
		{
			l->push_back(tmp);
		}
		//tmp = new SearchArea((hangle+langle)/2,hangle,(minDist+maxDist)/2,maxDist,center,ownPos);
		tmp = getAnArea((hangle+langle)/2,hangle,(minDist+maxDist)/2,maxDist,center,ownPos);
		if (tmp->isValid())
		{
			l->push_back(tmp);
		}
		return l;
	}

	bool AlloSearchArea::isValid()
	{
		if (!field->isInsideField(this->midP, -500))
		{
			return false;
		}
		if (field->isInsideOwnPenalty(this->midP, 100))
		{
			return false;
		}
		if (field->isInsideEnemyKeeperArea(this->midP, 100))
		{
			return false;
		}
		return true;
	}

	string AlloSearchArea::toString()
	{
		stringstream ss;
		ss << "Angle: " << (langle * 180 / M_PI) << " " << (hangle * 180 / M_PI) << "\n" << "Dist: " << minDist << " "
				<< maxDist << "\n" << "P : " << midP->x << " " << midP->y << "\n" << "Eval: " << val << "\n======"
				<< endl;
		return ss.str();
	}

	AlloSearchArea::AlloSearchArea(double langle, double hangle, double minDist, double maxDist,
									shared_ptr<geometry::CNPoint2D> center, shared_ptr<geometry::CNPosition> ownPos) :
			SearchArea(langle, hangle, minDist, maxDist, center, ownPos)
	{
	}

} /* namespace msl */