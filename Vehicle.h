/*
 * Vehicle.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class Vehicle {
protected:
	int bornTime;
	char destination;
public:
	Vehicle();
	Vehicle(char ddest);
	virtual ~Vehicle();
	int getTime();
	char getDestination();
	std::string stringify();
	bool isNull(){
		return false;
	}

};

#endif /* VEHICLE_H_ */
