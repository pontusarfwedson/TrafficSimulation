/*
 * Lane.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "Lane.h"
#include "Vehicle.h"
#include <vector>
#include <algorithm>
#include <cstddef>

namespace lane {

  Lane::Lane(int length) {
  	// TODO Auto-generated constructor stub
    std::fill(theLane.begin(),theLane.begin()+length, NULL);

  }

  std::string Lane::stringify() {
     std::string res = "";
      for (int i= 0; i<theLane.size(); i++) {
          if (theLane[i]==NULL)
              res += " ";
          else
              res += theLane[i].stringify();
      }
      return "<" + res + ">";

  }

  void Lane::step() {
   for (int i = 1; i<theLane.size(); i++) {
      if( theLane[i-1]==NULL ) {
        theLane[i-1] = theLane[i];
        theLane[i]   = NULL;
      }
    }
  }

  Vehicle Lane::removeFirst() {
    Vehicle result = theLane[0];
    theLane[0] = NULL;
    return result;
  }

  Vehicle Lane::getFirst() {
    return theLane[0];
  }

  boolean Lane::lastFree() {
    return theLane[theLane.size()-1]==NULL;
  }

  void Lane::putLast(Vehicle v) {
      theLane[theLane.size()-1] = v;
  }

  Lane::~Lane() {
  	// TODO Auto-generated destructor stub
  }

} /* namespace query_namespace */
