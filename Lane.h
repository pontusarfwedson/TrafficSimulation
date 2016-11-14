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

namespace lane {

class Lane {
private:
std::vector<Vehicle> theLane;

/*** Constructs a lane with a specified capacity
* length is The length (capacity) of the lane in number of vehicles
*/


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

} /* namespace query_namespace */
#endif /* LANE_H_ */
