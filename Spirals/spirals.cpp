//Header files
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;  // maximum starting number


//Function Declarations
void make_spiral(int spiral[][MAX_SIZE], string& direction, int& col_index, int& row_index, int& move_by, int& number, int& places_filled);
void do_spiral(const int n, const int start);
void print_spiral(int spiral[][MAX_SIZE], int n);

//Main function
int main()
{
	do_spiral(1, 1);
	do_spiral(5, 1);
	do_spiral(9, 11);
	do_spiral(12, 13);
	do_spiral(15, 17); 
}

//Function to make spiral
//Parameters passed include the spiral size , direction, col index, row index, move_by, number and places filled.
void make_spiral(int spiral[][MAX_SIZE], string& direction, int& col_index, int& row_index, int& move_by, int& number, int& places_filled)
{
	if(direction == "Center")
			{
				spiral[row_index][col_index] = number++;
				direction = "Right";
				row_index++;
				places_filled++;
			}
			else if(direction == "Right")
			{
				
				col_index++;
				row_index--;
				for(int i = 0; i < move_by; i++)
				{
					spiral[row_index][col_index] = number++;
					col_index++;
					places_filled++;
				}
				direction = "Up";
			}
			else if(direction == "Up")
			{

				row_index--;
				col_index--;
				for(int i = 0; i < move_by; i++)
				{
					spiral[row_index][col_index] = number++;
					row_index--;
					places_filled++;
				}
				direction = "Left";
			}
			else if(direction == "Left")
			{

				row_index++;
				col_index--;
				move_by++;
				for(int i = 0; i < move_by; i++)
				{
					spiral[row_index][col_index] = number++;
					col_index--;
					places_filled++;
				}
				direction = "Down";
			}
			else if(direction == "Down")
			{

				row_index++;
				col_index++;
				for(int i = 0; i < move_by; i++)
				{
					spiral[row_index][col_index] = number++;
					row_index++;
					places_filled++;
				}
				move_by++;
				direction = "Right";
			}
}

//Function to print spiral
void print_spiral(int spiral[][MAX_SIZE], int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(5) << spiral[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

//Function to check the spiral size 
//Parameters passed include the size and start value
//Function in turn calls make_spiral() and print_spiral()
void do_spiral(const int n, const int start)
{
	cout << "Spiral of size " << n << " starting at " << start << "\n";
	if( n % 2 == 0)
		cout << "***** Error: Size " << n << " must be odd. \n\n";
	
	else if(start > MAX_START)
		cout<< "***** Error: Size should be > 0 and less than"<<MAX_START<<"\n";
	else
	{
		int move_by = 1;					//number of places to move which is initially set to one
		string direction = "Center";		//Initial direction is set to the center of the matrix
		int row_index = (n/2);				//Initial row index set to n/2
		int col_index = (n/2);			    //Initial col index set to n/2
		int spiral[MAX_SIZE][MAX_SIZE];		//Create spiral of max size
		int number = start;					//Set number to the start position
		int places_filled = 0;				//Initial number of places filled is zero
		while(places_filled < n*n)			
		{
			make_spiral(spiral,direction,col_index,row_index,move_by,number,places_filled); //Function call to make_spiral()
		}
		
		print_spiral(spiral,n);             //Function call to print_spiral()
		
	}
	
}
