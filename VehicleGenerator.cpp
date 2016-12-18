/*
 * VehicleGenerator.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstddef>
#include <stdio.h>
#include "VehicleGenerator.h"
#include "NullVehicle.h"

using namespace std;

/**
 * Hard coded probabilities for test purposes only.
 * The used probabilities will most certainly produce traffic jam.
 */

VehicleGenerator::VehicleGenerator() {
	// TODO Auto-generated constructor stub

	periods.push_back(30);         // Time step 0 - 29
	arrivalProbabilities.push_back(0.7);
	turningProbabilities.push_back(0.5);
	comments.push_back("First interval");

	periods.push_back(30 + 20);    // Time step 30 - 49
	arrivalProbabilities.push_back(0.8);
	turningProbabilities.push_back(0.7);
	comments.push_back("Second intervall");

  //TODO CHECK with Pontus if periods.get(periods.size()-1)
	// is meants to get the last element of ArrayList.
	totalCycle = periods.at(periods.size()-1);
	myTime = 0;
	period = 0;
}

VehicleGenerator::~VehicleGenerator() {
	// TODO Auto-generated destructor stub
}

/**
 * Should generate a car OR truck OR null depending on probabilities.
 */
Vehicle VehicleGenerator::step(){

	myTime = myTime+1;
    if (myTime >= totalCycle) {
      myTime = 0;
      period = 0;
    }

    if (myTime>=periods.at(period)) {
      period++;
    }

    Vehicle retur = Vehicle(' ');
    double prob = arrivalProbabilities.at(period);

    if (((rand()%11)/10.0) < prob) {
      if (((rand()%11)/10.0) < turningProbabilities.at(period)) {
        retur = Vehicle('S');
      } else {
        retur = Vehicle('W');
      }
    }
    return retur;
}

/**
   * Returns the current state
   */
  string VehicleGenerator::toString() {

		return to_string(myTime) + ": <" + to_string(period) + ", " + to_string(arrivalProbabilities.at(period))
			+ ", " + to_string(turningProbabilities.at(period)) + ">";
  }

	/**
   * Prints the current setup of the generator
   */
  void VehicleGenerator::print() {
    int nsteps = 0;
    for (int i= 0; i<periods.size(); i++) {
			cout << periods.at(i) - nsteps << ", "
				<< arrivalProbabilities.at(i) << ", "
				<< turningProbabilities.at(i) << ", "
				<< comments.at(i) << ", " << endl;
			nsteps = periods.at(i);
		}
  }

  // int main() {
	// 	srand(time(0)); //TODO This should be called only once
  //   VehicleGenerator vg = VehicleGenerator();
  //   cout << "VehicleGenerator setup:" << endl;
  //   vg.print();
  //   cout << "\nStepping the generator:" << endl;
  //   for (int i= 0; i<300; i++) {
  //     vg.print();
  //     Vehicle v = vg.step();
  //     if (v.getDestination() != ' ') {
  //       cout << "  Vehicle out: <" <<
  //     		v.getDestination() << ", " << v.getTime() << ">" << endl;
  //     }
	// 		else
	// 		{
	// 			cout << "  NO Vehicle out" << endl;
	// 		}
  //   }
  // }
