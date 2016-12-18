/*
 * VehicleGenerator.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef VEHICLEGENERATOR_H_
#define VEHICLEGENERATOR_H_

#include <vector>
#include <string>
#include <cstddef>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace vehicleGenerator {
	class VehicleGenerator {

	private:
		vector<int> periods;
		vector<double> arrivalProbabilities;
		vector<double> turningProbabilities;
		vector<string> comments;

		int myTime;       // internal clock
	  int period;     // current period
	  int totalCycle; // total time period

	public:
		VehicleGenerator();
		VehicleGenerator(string);
		virtual ~VehicleGenerator();
		Vehicle step();
		string toString();
		void print();
	};
} // vehicleGenerator
#endif /* VEHICLEGENERATOR_H_ */
