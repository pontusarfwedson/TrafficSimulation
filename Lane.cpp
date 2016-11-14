/*
 * Lane.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Lane.h"
#include "Vehicle.h"
#include "NullVehicle.h"
//#include "Vehicle.h"
#include <vector>
#include <algorithm>
#include <cstddef>

namespace lane {

  Lane::Lane(int length) {
  	// TODO Auto-generated constructor stub
    std::fill(theLane.begin(),theLane.begin()+length, NullVehicle());

  }

  std::string Lane::stringify() {
     std::string res = "";
      for (int i= 0; i<theLane.size(); i++) {
        res += theLane[i].stringify();
      }
      return "<" + res + ">";

  }

  void Lane::step() {
   for (int i = 1; i<theLane.size(); i++) {
      if( theLane[i-1].isNull() ) {
        theLane[i-1] = theLane[i];
        NullVehicle temp;
        theLane[i]   = temp;
      }
    }
  }

  Vehicle Lane::removeFirst() {
    Vehicle result = theLane[0];
    NullVehicle temp;
    theLane[0] = temp;
    return result;
  }

  Vehicle Lane::getFirst() {
    return theLane[0];
  }

  bool Lane::lastFree() {
    return theLane[theLane.size()-1].isNull();
  }

  void Lane::putLast(Vehicle v) {
      theLane[theLane.size()-1] = v;
  }

  Lane::~Lane() {
  	// TODO Auto-generated destructor stub
  }

} /* namespace query_namespace */
