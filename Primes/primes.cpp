#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing


//FUNCTION DECLARATIONS
void print_primes(bool numbers[]);  			// Function to print prime numbers
void compute_primes(bool numbers[], int n);	    //Function to compute prime numbers 


void compute_primes(bool numbers[], int n)
{
    // index of array = Number
    for(int i = 2; i * i < n; i++)
    {
        // if flag of number is 1 then setting its multiples as 0
        if(numbers[i] == 1)
        {
            // Loop to set all multiples of Number to 0
            for(int j = i*i; j < n; j = j + i)
                numbers[j] = 0;
        }
    }
    print_primes(numbers);
}


void print_primes(bool numbers[])
{
    int counter = 0;
     for(int i = 2; i < MAX_NUMBER; i++)
     {
        // Printing only those numbers whose flag remains 1 
        if(numbers[i] == 1)
        {
            if(counter == ROW_SIZE)
            {
                cout << "\n";
                counter = 0;
            }
            cout << i <<" "<<setw(3);
            counter ++;
        }
     }
     cout << "\n";
     cout << "\n";
     cout << " Done!";
}

int main()
{
    bool numbers[MAX_NUMBER]; 
    // Initializing array with setting flags = true for all indices
    for(int i = 2; i < MAX_NUMBER; i++)
    {
        numbers[i]=true;
    }
    compute_primes(numbers,MAX_NUMBER);
}
