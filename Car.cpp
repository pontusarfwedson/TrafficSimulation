/*
 * Car.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Car.h"

Car::Car(char ddest){
	destination = ddest;
	length = 1;
}
Car::Car() {
	// TODO Auto-generated constructor stub

}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

std::string Car::stringify(){
	return destination;
}

