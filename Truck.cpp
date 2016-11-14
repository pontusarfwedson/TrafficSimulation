/*
 * Truck.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Truck.h"

Truck::Truck(char ddest){
	destination = ddest;
	length = 3;
}
Truck::Truck() {
	// TODO Auto-generated constructor stub

}

Truck::~Truck() {
	// TODO Auto-generated destructor stub
}

std::string Truck::stringify(){
	return "_" + destination + "_";
}
 /* namespace query_namespace */
