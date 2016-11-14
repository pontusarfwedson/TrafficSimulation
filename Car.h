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

class Car : public Vehicle{
private:
	int length;
public:
	Car(char ddest);
	Car();
	virtual ~Car();
	string stringify();
};
#endif /* CAR_H_ */
