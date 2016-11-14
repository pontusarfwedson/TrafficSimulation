/*
 * Car.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef CAR_H_
#define CAR_H_

#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class NullVehicle : public Vehicle{
private:
	int length;
public:
	NullVehicle(char ddest){};
	NullVehicle() {};
	~NullVehicle() {}
	std::string stringify(){};

	bool isNull(){
		return true;
	}
};
#endif /* CAR_H_ */
