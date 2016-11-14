/*
 * Truck.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef TRUCK_H_
#define TRUCK_H_

#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class Truck : public Vehicle {
private:
	int length;
public:
	Truck(char ddest);
	Truck();
	virtual ~Truck();
	std::string stringify();
	bool isNull(){
		return false;
	}
};

#endif /* TRUCK_H_ */
