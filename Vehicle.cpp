/*
 * Vehicle.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Vehicle.h"

Vehicle::Vehicle(char ddest){
	destination = ddest;
	bornTime = 0;
}

Vehicle::Vehicle() {
	// TODO Auto-generated constructor stub

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
	return destination;
}
