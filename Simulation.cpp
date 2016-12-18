/*
 * Simulation.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <iostream>
#include "trafficsystem.h"

using namespace std;


static int myTime = 0;
static bool simulationRun = false;
static int runTime = 100;

/**
* Returns current simulation myTime
* @return current myTime step
*/
  int getTime() {
    return myTime;
  }


  int main()
  {
    simulationRun = true;
    trafficsystem::TrafficSystem tf = trafficsystem::TrafficSystem();
    tf.printSetup();
    tf.print();
    tf.step();
    tf.print();

  }
