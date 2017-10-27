/* AUTHOR: SALONI KAJALE
SJSU ID: 012438998
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
const int UNITS_PER_CAN = 3;
const string INPUT_FILE_NAME = "counts.txt";

ifstream input;
input.open(INPUT_FILE_NAME.c_str());
if (input.fail())
{
cout << "Failed to open " << INPUT_FILE_NAME << endl;
return -1;
}

int plant_count, steps_near = 0, steps_far, water_remaining = UNITS_PER_CAN, cum_near_step_units = 0, cum_far_step_units = 0; //variable declaration


do
{

input >> plant_count;
if(plant_count != 0) // Checking if the number of plants is not equal to zero
{
// Plan Near
steps_near = 0, steps_far = 0, water_remaining = UNITS_PER_CAN, cum_near_step_units = 0, cum_far_step_units = 0; //Flushing all values


cout << endl;
cout << "==========================" << endl;
cout << " Plan Near with " << plant_count << " plants" << endl;
cout << "==========================" << endl;
cout << endl;
cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
cout << "---------  ----------  ----------  ---------------" << endl;


// CODE FOR PLAN NEAR
int lcv = 0;
cum_near_step_units = water_remaining;						

for (lcv = 0; lcv < plant_count; lcv++)                    //lcv is loop control variable and current plant number
{   
	if (water_remaining)
	{
		steps_near++;                                      //Increment steps
		cout<<"Plant "<<lcv+1<<"\t\t"<<steps_near<<"\t\t"<<water_remaining<<"\t\t"<<cum_near_step_units<<endl;
		water_remaining--;								  //Decrement water
		cum_near_step_units+=water_remaining;
	}

	else
	{
		steps_near += (lcv);							// When water=0 and returning to faucet
		cout<<"Faucet\t\t"<<steps_near<<"\t\t"<<water_remaining<<"\t\t"<<cum_near_step_units<<endl;
		water_remaining = UNITS_PER_CAN;				//Fill water again
		cum_near_step_units += (lcv+1)*water_remaining; //next plant number * weight of water
		steps_near+=(lcv);								
		lcv--;
	}
}
cum_near_step_units += ((lcv-1)*water_remaining);	   
   
steps_near+=(lcv);
cout<<"FAUCET\t\t"<<steps_near<<"\t\t"<<water_remaining<<"\t\t"<<cum_near_step_units<<endl;
cout<<"\nPlan Near: Total steps = "<<steps_near<<", Total step-units = "<<cum_near_step_units<<endl;


// Plan Far

cout << endl;
cout << "=========================" << endl;
cout << " Plan Far with " << plant_count << " plants" << endl;
cout << "=========================" << endl;
cout << endl;
cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
cout << "---------  ----------  ----------  ---------------" << endl;

//CODE FOR PLAN FAR:
lcv = 0;
water_remaining = UNITS_PER_CAN;
steps_far = plant_count - 1, cum_far_step_units = plant_count*water_remaining;

for (lcv = plant_count; lcv > 0; lcv--)                    //lcv is loop control variable and current plant number
{
	if (water_remaining)
	{
		steps_far++;
		cout<<"Plant "<<lcv<<"\t\t"<<steps_far<<"\t\t"<<water_remaining<<"\t\t"<<cum_far_step_units<<endl;
		water_remaining--;
		cum_far_step_units += water_remaining;
	}
   
	else
	{
		lcv++;
		steps_far += (lcv);
		cout<<"Faucet\t\t"<<steps_far<<"\t\t"<<water_remaining<<"\t\t"<<cum_far_step_units<<endl;
		water_remaining = UNITS_PER_CAN;
		cum_far_step_units += (lcv-1)*water_remaining;
		steps_far+=(lcv-2);
	}
}
steps_far+=(lcv+1);
cout<<"FAUCET\t\t"<<steps_far<<"\t\t"<<water_remaining<<"\t\t"<<cum_far_step_units<<endl;


cout<<"\nPlan Far: Total steps = "<<steps_far<<", Total step-units = "<<cum_far_step_units<<endl;

// CODE TO DETERMINE BETTER PLAN: 
cout << endl;
cout << "*** With " << plant_count << " plants, ";
if (cum_far_step_units > cum_near_step_units) 
{
	cout<<"Plan Near is better with "<<cum_far_step_units-cum_near_step_units<<" fewer step-units.\n";
}
else if (cum_far_step_units < cum_near_step_units)
{
	cout<<"Plan Far is better with "<<cum_near_step_units-cum_far_step_units<<" fewer step-units.";
}
else
{
	cout<<"Both plans are equally efficient";
}

}
} while (plant_count > 0);

return 0;
}
