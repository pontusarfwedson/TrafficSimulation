/*
 * Lane.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef LANE_H_
#define LANE_H_

#include "Vehicle.h"
#include <vector>
#include <string>

class Lane {
private:
std::vector<Vehicle> theLane;

public:
	Lane(int length);
	std::string stringify();
	void step();
	Vehicle removeFirst();
	Vehicle getFirst();
	bool lastFree();
	void putLast(Vehicle v);
	virtual ~Lane();
};
#endif /* LANE_H_ */
