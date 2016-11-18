/*
 * VehicleGenerator.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <fstream>
#include <iostream>
#include "VehicleGenerator.h"

using namespace std;

/**
 * Hard coded probabilities for test purposes only.
 * The used probabilities will most certainly produce traffic jam.
 */

VehicleGenerator::VehicleGenerator() {
	// TODO Auto-generated constructor stub

	periods.push_back(30);         // Time step 0 - 29
	arrivalProbabilities.push_back(0.7);
	turningProbabilities.push_back(0.5);
	comments.push_back("First interval");

	periods.push_back(30 + 20);    // Time step 30 - 49
	arrivalProbabilities.push_back(0.8);
	turningProbabilities.push_back(0.7);
	comments.push_back("Second intervall");

  //TODO CHECK with Pontus if periods.get(periods.size()-1)
	// is meants to get the last element of ArrayList.
	totalCycle = periods.at(periods.size()-1);
	time = 0;
	period = 0;
}

/**
 * This constructor reads the arrival and turning probabilities for different time
 * periods from a file.
 * <p>
 * Each line of input defines the probabilities for a specific period with the
 * following contents <br>
 * <ol>
 *   <li> Number of time steps (int).</li>
 *   <li> Arrival probability (double) [0, 1].</li>
 *   <li> Turning probability (double) [0, 1].</li>
 *   <li> Optional comment. Ignored. </li>
 * </ol>
 * <p>
 * <b>Example:</b> The following five lines defines five periods of
 * length 100, 20, 60, 30 and 50, respectively with
 * different arrival and turning probabilities.
 *
 * <pre>
 *      100   0.2   0.3   Night
 *       20   0.8   0.8   Morning rush rush
 *       60   0.5   0.5   Day
 *       30   0.7   0.6   Afternoon rush
 *       50   0.8   0.4   Evening
 * </pre>
 *
 * @param filename name of file with probabilities (US conventions)
 */
VehicleGenerator::VehicleGenerator(string filename)
{
	ifstream fin;
  //TODO
	//check Pontus with if "filemane" contains extensions
	//Fg. myFile.txt
	//I am assuming yes it contains.

	fin.open(filename);
	//checking if file is open successfully.
	if(!fin.good())
	{
		cout << "ERROR: READING FILE FAILURE." << endl;
	}
	else
	{
		int limit = 0;
		//reading until it reaches eof() {End of File}
		while (!fin.eof()) {
			/*TODO what does
			* lineScanner.useLocale(Locale.US);
			* do? */

			

			limit = limit + lineScanner.nextInt();
			periods.add(limit);
			arrivalProbabilities.add(lineScanner.nextDouble());
			turningProbabilities.add(lineScanner.nextDouble());
			comments.add(lineScanner.nextLine());
		}
		totalCycle = periods.get(periods.size()-1);
		time = 0;
		period = 0;
	}
}

VehicleGenerator::~VehicleGenerator() {
	// TODO Auto-generated destructor stub
}

/**
 * Should generate a car OR truck OR null depending on probabilities.
 */
Vehicle VehicleGenerator::step(){
	//Vehicle* temp = new Car('W');
	//return *temp;
	//return NULL;
}
