/*
 * Light.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Light.h"

namespace light {

/**
 * Constructors and destructors
 */
Light::Light(int pperiod, int ttime){
	time = 0;
	period = pperiod;
	time = ttime;
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
void Light::step(){
	time = (time + 1)%period;
}
bool Light::isGreen(){
	return time < green;
}

string Light::stringify(){
	if(isGreen())
		return "(G)";
	else
		return "(R)";
}

int main(){
	Light lightW = new Light(5, 3);
	Light lightS = new Light(5, 2);
	for (int i=0; i<12; i++) {
		std::cout << i << ":  (5,3): " << lightW << "  (5,2): " << lightS << std::endl;
		lightW.step();
		lightS.step();
	}
	return 0;
}

} /* namespace light */
