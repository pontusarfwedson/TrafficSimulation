/*
 * Light.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class Light {
private:
	int period;
	int green;
	int time;
public:
	Light(int pperiod, int ttime);
	Light();
	virtual ~Light();

	int getTime();
	void step();
	bool isGreen();
	std::string stringify();
};

#endif /* LIGHT_H_ */
