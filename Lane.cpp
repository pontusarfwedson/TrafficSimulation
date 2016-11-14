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

#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>
using namespace std;


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

/*
int main() {
  srand (time(NULL));
  Lane lane = Lane(10);
  for (int i = 0; i<20; i++) {
    if (!lane.getFirst().isNull()) {
      cout << "Out from lane: " << lane.removeFirst().stringify() << endl;
    }
    lane.step();
    if (rand()<0.5) {
      lane.putLast(Vehicle('x'));
    }
    cout << lane.stringify() << endl;
  }
  cout << endl;
  if (lane.lastFree()) {
    lane.putLast(Vehicle('y'));
    cout << lane.stringify() << endl;
  }
  cout << "Time to crash!" << endl;
  lane.putLast(Vehicle('z'));
}

*/
