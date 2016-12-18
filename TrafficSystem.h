/*
 * TrafficSystem.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef TRAFFICSYSTEM_H_
#define TRAFFICSYSTEM_H_

#include<vector>
#include<string>
#include"Vehicle.h"
#include"VehicleGenerator.h"
#include"Lane.h"
#include"Light.h"

using namespace std;

namespace trafficsystem {

class TrafficSystem {
private:
	int laneLength;
	int laneWSLength;
	int lightPeriod;
	int lightWestGreen;
	int lightSouthGreen;

  VehicleGenerator generator;
  vector<Vehicle> queue;
  Lane   lane;
  Lane   laneWest;
  Lane   laneExitWest;
  Lane   laneSouth;
  Lane   laneExitSouth;
  Light  lightWest;
  Light  lightSouth;

  int blocked;	  // Number of time step blocking has occured
  int queued; 		// Number of time steps with queued vehicles

public:
	TrafficSystem(int, int, int, int, int);
	void step();
	void print();
	string qtos();
	void printSetup();
	virtual ~TrafficSystem();
};

} /* namespace query_namespace */
#endif /* TRAFFICSYSTEM_H_ */
