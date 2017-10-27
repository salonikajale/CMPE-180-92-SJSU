//HEADER FILES
#include <iostream>
#include <iomanip>
#include <vector>
 
using namespace std;
 
const int MAX_START = 50;   // maximum starting number
 
//Function declarations
void compute_primes(vector<bool> &numbers,int n, int start);
void make_spiral(vector <vector<char> > &spiral, string &direction, int& col_index, int& row_index, int& move_by, int& number, int& places_filled);
void do_prime_spiral(const int n, const int start);
char replaceNumber(vector<bool> number,int num);
void print_spiral(vector <vector<char> > &spiral, int n);


//Main Function
int main()
{
	do_prime_spiral(5, 1);
	do_prime_spiral(25, 11);
	do_prime_spiral(35, 0);
	do_prime_spiral(50, 31);
	do_prime_spiral(101, 41);
}
 
//Function to compute prime numbers using 1D vector
 void compute_primes(vector<bool> &numbers,int n, int start)
{
	numbers[0] = false;
	numbers[1] = false;
	// index of vector = Number
	for(int i = 2; i*i < (n*n+start); i++)
	{
		// if flag of number is 1 then setting its multiples as 0
		if(numbers[i] == true)
		{
			// Loop to set all multiples of Number to 0
			for(int j = i*i; j < (n*n + start); j = j + i)
				numbers[j] = false;
		}
	}
	
}

//Function to make spiral
//Parameters include the 2D vector spiral, direction, col_index, row_index, move_by, number, places filled and 1D vector of primes
void make_spiral(vector <vector<char> > &spiral, string &direction, int& col_index, int& row_index, int& move_by, int& number, int& places_filled,vector<bool> primes)
{
	if(direction == "Center")
	{
			spiral[row_index][col_index] = replaceNumber(primes,number++);
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
			spiral[row_index][col_index] = replaceNumber(primes,number++);
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
	  
			spiral[row_index][col_index] = replaceNumber(primes,number++);
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
		spiral[row_index][col_index] = replaceNumber(primes,number++);
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
			spiral[row_index][col_index] = replaceNumber(primes,number++);
			row_index++;
			places_filled++;
		}
		move_by++;
		direction = "Right";
	}
}


//Function to create a prime spiral which checks if the input is prime and also checks if the start value is less than the maximum start
void do_prime_spiral(const int n, const int start)
{
	cout << "Prime Spiral of size " << n << " starting at " << start<<"\n";
	if( n % 2 == 0)
		{
		cout << "***** Error: Size " << n << " must be odd. \n";
		cout<<endl;
		}
		else if( start <= 0 || start > MAX_START)
		{
		   cout<< "***** Error: Starting value 0 < 1 or > 50"<<endl;
		   cout<< endl;
		}
	else
	{
		int move_by = 1;  									//Set move_by to 1 initially
		string direction = "Center";						//Set string direction to Center as we have to start filling form the middle
		int row_index = (n/2);								//Initial position of row_index
		int col_index = (n/2);								//Initial position of column_index
		vector <vector<char> > spiral(n, vector<char>(n));	//Creating a 2D vector 
		int number = start;									// Initializing number to start value
		int places_filled = 0;								// Initializing places_filled to zero
		vector<bool> primes((n*n) + start,true);			// Creating A 1D vector for prime numbers
		compute_primes(primes,n,start);						//Function call to compute_primes()
		while(places_filled < (n*n))
		{
			make_spiral(spiral, direction, col_index, row_index, move_by,number, places_filled,primes);  //Function call to make_spiral()
		}
		cout<<endl;
		print_spiral(spiral,n);
 
	}
 
}
 
//Function to replace the prime values with # and non prime with a .
// Parameters used include a bool vector and int number
char replaceNumber(vector<bool> number,int num) {
	if (number[num]==true) {
		return '#';
	}
	return '.';
}
 
//Function to print_spiral
//Parameters include a 2D vector and n
void print_spiral(vector <vector<char> > &spiral, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(1) << spiral[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}


