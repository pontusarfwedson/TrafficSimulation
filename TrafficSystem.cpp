/*
 * TrafficSystem.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <iostream>
#include <string>
//#include <time.h>
#include <unistd.h>
#include "TrafficSystem.h"
#include "Vehicle.h"
#include "VehicleGenerator.h"
#include "Lane.h"
#include "Light.h"
using namespace std;

namespace trafficsystem {

TrafficSystem::TrafficSystem(int laneLength, int laneWSLength,
    int lightPeriod, int lightWestGreen, int lightSouthGreen) {
	  // TODO Auto-generated constructor stub

    this->laneLength      = laneLength;
    this->laneWSLength    = laneWSLength;
    this->lightPeriod     = lightPeriod;
    this->lightWestGreen  = lightWestGreen;
    this->lightSouthGreen = lightSouthGreen;

    generator     = VehicleGenerator();
    lane          = Lane(laneLength);
    laneWest      = Lane(laneWSLength);
    laneExitWest  = Lane(3);             // Just for illustration
    laneSouth     = Lane(laneWSLength);
    laneExitSouth = Lane(3);             // Just for illustration
    lightWest     = Light(lightPeriod, lightWestGreen);
    lightSouth    = Light(lightPeriod, lightSouthGreen);
}

/**
   * Advances the whole traffic system one timestep. Makes use
   * of components step methods
   */
  void TrafficSystem::step() {
    Vehicle v;

                                                // Vehicle leaving at West?
    v = laneExitWest.removeFirst();
    if (v.getDestination()!=' ') {
      //exitWest.push_back(Simulation.getTime() - v.getTime());
    }
    laneExitWest.step();

                                                // Vehicle leaving at South?
    v = laneExitSouth.removeFirst();
    if (v.getDestination()!=' ') {
      //exitSouth.push_back(Simulation.getTime() - v.getTime());
    }
    laneExitSouth.step();


                                                 // Take vehicles past the lights if possible
    if (lightWest.isGreen() ) {
      laneExitWest.putLast(laneWest.removeFirst());
    }
    if (lightSouth.isGreen()) {
      laneExitSouth.putLast(laneSouth.removeFirst());
    }

                                                 // Step lanes in front of the lights
    laneWest.step();
    laneSouth.step();

                                                 // Move from lane to laneWest or laneSouth
    v = lane.getFirst();
    if (v.getDestination()!=' ') {
      if (v.getDestination()=='W' )
        if (laneWest.lastFree() )
        laneWest.putLast(lane.removeFirst());
      else
        blocked++;
      else if (laneSouth.lastFree())
        laneSouth.putLast(lane.removeFirst());
      else
        blocked++;
    }

                                                 // Step first lane
    lane.step();

                                                 // Create vehicles
    v = generator.step();
    if (v.getDestination()!=' ') {
      queue.push_back(v);
    }
    if (!queue.empty() && lane.lastFree()) {
      lane.putLast(queue.front());
      queue.erase(queue.begin());
    }
    if (!queue.empty()) {
       queued++;
    }

                                                  // Step signals
    lightWest.step();
    lightSouth.step();
  }

  /**
   * Prints the current situation using toString-methods in
   * lights and lanes.
   * Example:
   * <pre>
   * (G) &lt;WWW W W  W&gt;&lt; W SW  W WS S&gt;   queue: [WWS]
   * (G) &lt S  SSS SS&gt;
   * </pre>
   */
  void TrafficSystem::print() {
    cout << laneExitWest.stringify() << " " << lightWest.stringify() << " " << laneWest.stringify();
    cout << lane.stringify();
    //cout << ln("   queue: " + qtos() + "  vg: " + generator);
    cout << qtos() << "     " << generator.toString() << endl;
    cout << laneExitSouth.stringify() << " " << lightSouth.stringify() << " " << laneSouth.stringify() << endl;;
  }

  string TrafficSystem::qtos() {
    string res = "";
    list<Vehicle>::iterator it;
    for (it = queue.begin(); it != queue.end(); it++) {
      res += it->stringify();
    }
    return '[' + res + ']';
  }

  /**
   * Prints the simulation parameters and arrival probabilities used in this run
   */
  void TrafficSystem::printSetup() {
    cout << "Simulation parameters:" << endl;
    cout << "\t laneLength     : " << laneLength << endl;
    cout << "\t laneWSLength   : " << laneWSLength << endl;
    cout << "\t lightPeriod    : " << lightPeriod << endl;
    cout << "\t lightSouthGreen: " << lightSouthGreen << endl;
    cout << "\t lightWestGreen : " << lightWestGreen << endl;
    cout << "\nTraffic periods and probabilities:" << endl;
    generator.print();
  }

TrafficSystem::~TrafficSystem() {
	// TODO Auto-generated destructor stub
}

} /* namespace query_namespace */

int main() {
  /*************************
   *    laneLength      : 10
   *    laneWSLength    :  8
   *    lightPeriod     : 14
   *    lightWestGreen  :  6
   *    lightSouthGreen :  4
   ************************/

  trafficsystem::TrafficSystem tf = trafficsystem::TrafficSystem(10, 8, 14, 6, 4);
  tf.printSetup();
  tf.print();
  for(int i = 0; i < 100; i++) {
    cout.flush();
    usleep(10000);
    //Sleep(10000); // for windows
    tf.print();
    tf.step();
  }
}
