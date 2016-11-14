/*
 * VehicleGenerator.h
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#ifndef VEHICLEGENERATOR_H_
#define VEHICLEGENERATOR_H_

#include <cstddef>

class VehicleGenerator {
public:
	VehicleGenerator();
	virtual ~VehicleGenerator();
	Vehicle step();
};

#endif /* VEHICLEGENERATOR_H_ */
