/*
 * Vehicle.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <string>
#include "Vehicle.h"
using namespace std;

//Default constructor
Vehicle::Vehicle() {
	// TODO Auto-generated constructor stub
}

Vehicle::Vehicle(char ddest){
	destination = ddest;
	bornTime = 0;
}

Vehicle::~Vehicle() {
	// TODO Auto-generated destructor stub
}

int Vehicle::getTime(){
	return bornTime;
}
char Vehicle::getDestination(){
	return destination;
}
std::string Vehicle::stringify(){
	return string(1, destination);
}
