/*
 * Car.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Car.h"

NullVehicle::NullVehicle(char ddest){
	destination = ddest;
	length = 1;
}
NullVehicle::NullVehicle() {
	// TODO Auto-generated constructor stub

}

NullVehicle::~NullVehicle() {
	// TODO Auto-generated destructor stub
}

std::string NullVehicle::stringify(){
	return " ";
}

