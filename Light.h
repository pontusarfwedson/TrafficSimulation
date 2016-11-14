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

namespace light{

class Light {
private:
	int period;
	int green;
	int time;
public:
	Light(int pperiod, int ttime);
	Light();
	virtual ~Light();

	void step();
	bool isGreen();
	string stringify();
};

} /* namespace query_namespace */
#endif /* LIGHT_H_ */
