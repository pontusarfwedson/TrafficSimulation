/*
 * Light.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Light.h"



/**
 * Constructors and destructors
 */
Light::Light(int pperiod, int ggreen){
	time = 0;
	period = pperiod;
	green = ggreen;
}

Light::Light() {
	// TODO Auto-generated constructor stub
	time = 0;
	period = 10;
	green = 5;
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}


/**
 * Public methods
 */
int Light::getTime(){
	return time;
}

void Light::step(){
	time = (time + 1)%period;
}
bool Light::isGreen(){
	return time < green;
}

std::string Light::stringify(){
	if(isGreen()){
		return "(G)";
	}
	else{
		return "(R)";
	}
}

int main(){
	Light * lightW = new Light(5, 3);
	Light * lightS = new Light(5, 2);
	for (int i=0; i<12; i++) {
		std::cout << "***************************" << std::endl;
		std::cout << i << ":  (5,3): " << lightW->stringify() << "  (5,2): " << lightS->stringify() << std::endl;
		std::cout << i << ":  (5,3): " << lightW->getTime() << "  (5,2): " << lightS->getTime() << std::endl;
		std::cout << "***************************" << std::endl;
		lightW->step();
		lightS->step();
	}
	return 0;
}

/* namespace light */
