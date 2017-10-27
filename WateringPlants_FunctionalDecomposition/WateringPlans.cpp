/**
 * Assignment 2. Watering Plans
 *
 * FUNCTIONAL DECOMPOSITION
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Fall 2017
 *
 * Author: Saloni Kajale
 *         Computer Engineering
 *         San Jose State University
 */

//Include Directives
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Constant Declarations
const int UNITS_PER_CAN = 3;
const string INPUT_FILE_NAME = "counts.txt";


//Function Declarations
void openFile(string filename, ifstream& file);
int getPlantCount(ifstream& inputFile);
void printHeaderText(bool flag,int plant_count);
void initializeVariables(int& plant_number, int& steps, int& cum_steps, int& cum_step_units_near, int plant_count, int unwatered_count, int water_amount, bool flag);
void printPlant(int plant_number, int cum_steps, int water_amount, int cum_step_units_near);
void printFaucet(int plant_number, int cum_steps, int water_amount, int cum_step_units_near);
void printSteps(int cum_steps, int cum_step_units_near, bool flag);
bool isTripDone(int water_amount, int unwatered_count);
void walkAwayFromFaucet(int& plant_number, int& cum_steps, int& cum_step_units_near, int water_amount);
void walkTowardsFaucet(int& plant_number, int& cum_steps, int& cum_step_units_far, int water_amount);
void walkBackToFaucet(int& steps, int plant_number, int& cum_steps, int& cum_step_units_near, int water_amount);
void wateringNearPlants(int plant_count,int UNITS_PER_CAN,int& cum_step_units_near);
void wateringFarPlants(int plant_count,int UNITS_PER_CAN,int& cum_step_units_far);
void getBetterPlan(int plant_count,int cum_step_units_near,int cum_step_units_far);
void wateringPlants(int plant_count, int UNITS_PER_CAN);


// Main Function
int main()
{
ifstream inputFile;
int plant_count;                                       // count of plants
openFile(INPUT_FILE_NAME, inputFile);                 // Function call to open a file
if (inputFile.is_open()) 
{
	do
	{
		plant_count = getPlantCount(inputFile);      // Function call to get the PlantCount
		if (plant_count <= 0) return 0;
		wateringPlants(plant_count, UNITS_PER_CAN); // Function call for wateringPlants()
		
	}while (plant_count > 0);
	return 0;
}
else
{
	cout << "Failed to open " << INPUT_FILE_NAME << endl;
}
}

//Function to open a file
void openFile(string filename, ifstream& file)
{
file.open(filename.c_str());
}

//Function to get the number of plants given in the input file
//The function returns the plant_count
int getPlantCount(ifstream& inputFile)
{
int plant_count;
inputFile >> plant_count;
return plant_count;
}

//Function to print the HeaderText()
//Parameters required flag and plant_count
void printHeaderText(bool flag,int plant_count)
{
cout << endl;
string direction;
if(flag)
	direction = "Near";
else
	direction = "Far";
cout << "==========================" << endl;
cout << " Plan " << direction << " with " << plant_count << " plants" << endl;
cout << "==========================" << endl;
cout << endl;
cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
cout << "---------  ----------  ----------  ---------------" << endl;
}


//Function for initializing variables
//Value of flag is used to check if the condition for Near or Far is to be considered.
void initializeVariables(int& plant_number, int& steps, int& cum_steps, int& cum_step_units_near, int plant_count, int unwatered_count, int water_amount, bool flag)
{
if(flag) // true indicates initialize for Near
	plant_number = plant_count - unwatered_count + 1;
else
	plant_number = unwatered_count;
	steps = plant_number;
	cum_steps += steps;
	cum_step_units_near += steps*water_amount;
}


//Function for printing plants
//Parameters include plant_number, cum_steps, water_amount, cum_step_units_near
void printPlant(int plant_number, int cum_steps, int water_amount, int cum_step_units_near)
{
cout << "Plant " << setw(2) << plant_number
				 << setw(9)  << cum_steps
				 << setw(11) << water_amount
				 << setw(16) << cum_step_units_near << endl;
}


//Function to printFaucet
//Parameters include plant_number, cum_steps, water_amount, cum_step_units_near
void printFaucet(int plant_number, int cum_steps, int water_amount, int cum_step_units_near)
{
cout << "FAUCET "
			 << setw(10) << cum_steps
			 << setw(11) << water_amount
			 << setw(16) << cum_step_units_near << endl;
}

//Function to printSteps()
//Parameters include cum_steps, cum_step_units_near,flag
void printSteps(int cum_steps, int cum_step_units_near, bool flag)
{
string direction;
if(flag)
	direction = "Near";
else
	direction = "Far";
cout << endl;
cout << "Plan " << direction << ": Total steps = " << cum_steps
<< ", total step-units = " << cum_step_units_near << endl;
}

//Function to check if isTripDone()
//Parameters required include water_amount, unwatered_count
bool isTripDone(int water_amount, int unwatered_count)
{
bool trip_done = (water_amount == 0) || (unwatered_count == 0);
return trip_done;
}

//Function to walkAwayFromFaucet()
//Parameters required include plant_number, cum_steps, cum_step_units-near, water_amount
void walkAwayFromFaucet(int& plant_number, int& cum_steps, int& cum_step_units_near, int water_amount)
{
plant_number++;
cum_steps++;
cum_step_units_near += water_amount;
}

//Function to walkTowardsFaucet()
//Parameters required include plant_number,  cum_steps, cum_step_units_far,water_amount
void walkTowardsFaucet(int& plant_number, int& cum_steps, int& cum_step_units_far, int water_amount)
{
plant_number--;
cum_steps++;
cum_step_units_far += water_amount;
}

//Function to WalkBackToFaucet()
//Parameters required include steps, plant_number, cum_steps, cum_steps_units_near, water_amount
void walkBackToFaucet(int& steps, int plant_number, int& cum_steps, int& cum_step_units_near, int water_amount)
{
steps = plant_number;
cum_steps += steps;
cum_step_units_near += steps*water_amount;
}


//Function for wateringNearPLants() 
//This function in turn calls printHeaderText(), initializeVariables(), printPlant(), isTripDone(), walkAwayFromFaucet(), 
//walkBackToFaucet(), printFaucet(), printSteps()
void wateringNearPlants(int plant_count,int UNITS_PER_CAN,int& cum_step_units_near)
{
int plant_number;           // plant #1, #2, #3, ...
int water_amount;           // amount of water in the watering can
int steps;                  // number of steps taken
int cum_steps;              // cumulative number of steps taken for a plan
bool trip_done;             // true if a trip is done

printHeaderText(true, plant_count);

int unwatered_count = plant_count;
cum_steps = 0;
cum_step_units_near = 0;
while (unwatered_count > 0)
	{
		// Fill the can.
		water_amount = UNITS_PER_CAN;

		// Walk to the nearest unwatered plant with a full can.
		initializeVariables(plant_number, steps, cum_steps, cum_step_units_near, plant_count, unwatered_count, water_amount, true);

		// Water plants while walking away from the faucet.
		// Loop once per plant until either the can is empty
		// or all the plants have been watered.
		// During each loop, water one plant.
		do
		{
			
			printPlant(plant_number, cum_steps, water_amount, cum_step_units_near);
			water_amount--;
			unwatered_count--;
			
			trip_done = isTripDone(water_amount, unwatered_count);
			if (!trip_done)
			{
				// Walk away from the faucet to the next unwatered plant.
				walkAwayFromFaucet(plant_number, cum_steps, cum_step_units_near, water_amount);
			}
		} while (!trip_done);

		// Walk back to the faucet with an empty or partially filled can.
		walkBackToFaucet(steps, plant_number, cum_steps, cum_step_units_near, water_amount);

		printFaucet(plant_number, cum_steps, water_amount, cum_step_units_near);

	}
	printSteps(cum_steps, cum_step_units_near, true);
}

//Function for WateringFarPlants()
//This function in turn calls printHeaderText(), initializeVariables(), printPlant(), isTripDone(), walkTowardsFaucet(), 
//walkBackToFaucet(), printFaucet(), printSteps()

void wateringFarPlants(int plant_count,int UNITS_PER_CAN,int& cum_step_units_far)
{
int plant_number;           // plant #1, #2, #3, ...
int water_amount;           // amount of water in the watering can
int steps;                  // number of steps taken
int cum_steps;              // cumulative number of steps taken for a plan
bool trip_done;             // true if a trip is done
printHeaderText(false, plant_count);
int unwatered_count = plant_count;
cum_steps = 0;
cum_step_units_far = 0;
while (unwatered_count > 0)
	{
		// Fill the can.
		water_amount = UNITS_PER_CAN;

		// Walk to the nearest unwatered plant with a full can.
		initializeVariables(plant_number, steps, cum_steps, cum_step_units_far, plant_count, unwatered_count, water_amount, false);

		// Water plants while walking away from the faucet.
		// Loop once per plant until either the can is empty
		// or all the plants have been watered.
		// During each loop, water one plant.
		do
		{
			
			printPlant(plant_number, cum_steps, water_amount, cum_step_units_far);
			water_amount--;
			unwatered_count--;
			
			trip_done = isTripDone(water_amount, unwatered_count);
			if (!trip_done)
			{
				// Walk away from the faucet to the next unwatered plant.
				walkTowardsFaucet(plant_number, cum_steps, cum_step_units_far, water_amount);
			}
		} while (!trip_done);

		// Walk back to the faucet with an empty or partially filled can.
		walkBackToFaucet(steps, plant_number, cum_steps, cum_step_units_far, water_amount);
		
		printFaucet(plant_number, cum_steps, water_amount, cum_step_units_far);

	}
	printSteps(cum_steps, cum_step_units_far, false);
}


//Function getBetterPlan() is used to check which plan is better
//Arguments required plant_count, cum_step_units_near, cum_step_units_far
void getBetterPlan(int plant_count,int cum_step_units_near,int cum_step_units_far)
{
cout << endl;
cout << "*** With " << plant_count << " plants, ";
if (cum_step_units_far == cum_step_units_near)
{
	cout << "both plans are equal." << endl;
}
else if (cum_step_units_far < cum_step_units_near)
{
	cout << "Plan Far is better with "
		 << cum_step_units_near - cum_step_units_far
		 << " fewer step-units." << endl;
}
else
{
	cout << "Plan Near is better with "
		 << cum_step_units_far - cum_step_units_near
		 << " fewer step-units." << endl;
}
}

//Function WateringPlants() is used for calling wateringNearPlants(), wateringFarPlants() and getBetterPlan()
//Parameters passed to the function include plant_count and UNITS_PER_CAN
void wateringPlants(int plant_count, int UNITS_PER_CAN)
{
int cum_step_units_far;
int cum_step_units_near;
wateringNearPlants(plant_count,UNITS_PER_CAN,cum_step_units_near);
wateringFarPlants(plant_count,UNITS_PER_CAN,cum_step_units_far);
getBetterPlan(plant_count,cum_step_units_near,cum_step_units_far);
}

