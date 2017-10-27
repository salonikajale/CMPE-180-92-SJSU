//HEADER FILES
#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
 
using namespace std;

//DECLARATION OF CONSTANTS
const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;                // desired decimal places
const int PRECISION      = PLACES + 1;          // +1 for the digit 3 before the decimal
 
const int BASE       = 10;                     	// base 10 numbers
const int BIT_COUNT  = 8;                      	// bits per machine word
 
const int BLOCK_SIZE = 10;                    	// print digits in blocks
const int LINE_SIZE  = 100;                  	// digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;    	// lines to print
const int GROUP_SIZE = 5;
 
//FUNCTION DECLARATION
void cube_root(mpf_t &xn_1,mpf_t a1);
 
int main()
{
 
mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits
//Variable initialization and declaration for pi, an, rn, sn
mpf_t pi;
mpf_init(pi);
mpf_t an;
mpf_init(an);
mpf_t rn;
mpf_init(rn);
mpf_t sn;
mpf_init(sn);

//Variable initialization and declaration for value_zero,value_one,value_two,value_three,value_nine,value_twentyseven
mpf_t value_zero;
mpf_init(value_zero);
mpf_t value_one;
mpf_init(value_one);
mpf_t value_two;
mpf_init(value_two);
mpf_t value_three;
mpf_init(value_three);
mpf_t value_nine;
mpf_init(value_nine);
mpf_t value_twentyseven;
mpf_init(value_twentyseven);
 
mpz_t value_one_t;
mpz_init(value_one_t);
mpz_set_ui(value_one_t,1.0);
 
//Setting values of the variables 
mpf_set_str(value_zero,"0.0",10);
mpf_set_str(value_one,"1.0",10);
mpf_set_str(value_two,"2.0",10);
mpf_set_str(value_three,"3.0",10);
mpf_set_str(value_nine,"9.0",10);
mpf_set_str(value_twentyseven,"27.0",10);
 
mpf_set(an,value_one); //Setting initial value of an
mpf_set(rn,value_one); //Setting initial value of rn
mpf_set(sn,value_one); //Setting initial value of sn
 

//Calculate a0 = 1/3
mpf_div(an,value_one,value_three);
 
 
//Calcuate r0 = (sqrt(3)-1)/2
mpf_sqrt(rn,value_three);
mpf_sub(rn,rn,value_one);
mpf_div(rn,rn,value_two);
 

//Calculate s0 = cbrt(1 - r0^3)
mpf_mul(sn,rn,rn);
mpf_mul(sn,sn,rn);
mpf_sub(sn,value_one,sn);
cube_root(sn,sn);
 
mpf_t tn_1;
mpf_init(tn_1);
 
mpf_t un_1;
mpf_init(un_1);
 
mpf_t vn_1; 
mpf_init(vn_1);
mpf_t temp_value1;
mpf_init(temp_value1);
mpf_t temp_value2;
mpf_init(temp_value2);
 
mpf_t wn_1; 
mpf_init(wn_1);
 
mpf_t an_1; mpf_init(an_1);
mpf_t temp_value3;mpf_init(temp_value3);
mpf_t temp_value4;mpf_init(temp_value4);
 
mpf_t sn_1; 
mpf_init(sn_1);
mpf_t temp_value5;
mpf_init(temp_value5);
mpf_t temp_value6;
mpf_init(temp_value6);
 
mpf_t rn_1; 
mpf_init(rn_1);
 
 
for(int i=0;i<MAX_ITERATIONS;i++)
{
 
//Calculate tn+1 = 1 + 2rn
mpf_mul(tn_1,rn,value_two);
mpf_add(tn_1,tn_1,value_one);
 
 
//Calculate un+1 = cuberoot(9rn(1 + rn + rn^2))
mpf_mul(un_1,rn,rn);
mpf_add(un_1,un_1,rn);
mpf_add(un_1,un_1,value_one);
mpf_mul(un_1,un_1,rn);
mpf_mul(un_1,un_1,value_nine);
cube_root(un_1,un_1);
 
 
//Calculate vn+1 = tn_1^2 + (tn_1*un_1) + un_1^2
mpf_mul(temp_value1,tn_1,tn_1);
mpf_mul(temp_value2,un_1,un_1);
mpf_mul(vn_1,tn_1,un_1);
mpf_add(vn_1,vn_1,temp_value1);
mpf_add(vn_1,vn_1,temp_value2);
 
 
//Calculate wn+1 = (27(1 + sn + sn^2))/vn_1
mpf_pow_ui(wn_1,sn,2);
mpf_add(wn_1,wn_1,sn);
mpf_add(wn_1,wn_1,value_one);
mpf_mul(wn_1,wn_1,value_twentyseven);
mpf_div(wn_1,wn_1,vn_1);
 

//Calculate an+1 = (wn_1*an) + ((3^(2n-1))(1 - wn_1)
mpf_sub(temp_value3,value_one,wn_1);
mpf_pow_ui(temp_value4,value_nine,i);
mpf_div(temp_value4,temp_value4,value_three);
mpf_mul(an_1,wn_1,an);
mpf_mul(temp_value3,temp_value3,temp_value4);
mpf_add(an_1,an_1,temp_value3);
 
 
//Calculate sn+1 = ((1 - rn)^3)/((tn_1 + 2un_1)vn_1)
mpf_sub(temp_value5,value_one,rn);
mpf_pow_ui(temp_value5,temp_value5,3);
mpf_mul(temp_value6,value_two,un_1);
mpf_add(temp_value6,tn_1,temp_value6);
mpf_div(sn_1,temp_value5,temp_value6);
mpf_div(sn_1,sn_1,vn_1);
 
 
//Calculate rn+1 = cuberoot(1 - sn_1^3)
mpf_pow_ui(rn_1,sn_1,3);
mpf_sub(rn_1,value_one,rn_1);
cube_root(rn_1,rn_1);
 
 
if(mpf_cmp(an_1,an)==0 && i!=0)
{
  gmp_printf("%.Ff\n",an_1);
  return 0;
}
 
 
mpf_set(an,an_1);//Setting initial value of an_1
mpf_set(rn,rn_1); //Setting initial value of rn_1
mpf_set(sn,sn_1);//Setting initial value of sn_1
mpf_div(pi,value_one,an);
}
 
 
//Printing the final output
char *my_pi;
mp_exp_t val1;
my_pi = mpf_get_str(my_pi,&val1,10,0,pi);
cout<<my_pi[0]<<".";
 
for(int j=1;j<PRECISION;j++)
{
	cout<<my_pi[j];
	if(j% BLOCK_SIZE == 0)
	cout<<" ";
	if(j% LINE_SIZE == 0)
	cout<<"\n  ";
	if(j% (PLACES/2) == 0)
	cout<<"\n  ";
}
return 0;
}
 
//CUBE ROOT FUNCTION
void cube_root(mpf_t &xn_1,mpf_t a1)
{
//Declaring and initializing variables
mpf_t a;mpf_init(a);
mpf_t value_zero;
mpf_init(value_zero);
mpf_t value_one;
mpf_init(value_one);
mpf_t value_two;
mpf_init(value_two);
mpf_t value_three;
mpf_init(value_three);


//Setting the values of the variables
mpf_set_str(value_zero,"0.0",BASE);
mpf_set_str(value_one,"1.0",BASE);
mpf_set_str(value_two,"2.0",BASE);
mpf_set_str(value_three,"3.0",BASE);
mpf_set(a,a1);
 
//Declaring and initializing values xn,xn_1,Halley_temp1,Halley_temp2
mpf_t xn;
mpf_init(xn);
mpf_div(xn,a,value_three);
mpf_init(xn_1);
mpf_t Halley_temp1;
mpf_init(Halley_temp1);
mpf_t Halley_temp2;
mpf_init(Halley_temp2);
 
for(int i=0; i<PLACES; i++)
{ 
//Halley's Method
mpf_mul(Halley_temp1,xn,xn);						//Halley_temp1= xn * xn
mpf_mul(Halley_temp1,Halley_temp1,xn);    			//Halley_temp1= Halley_temp1 * xn
mpf_mul(Halley_temp2,value_two,a); 					// 2 * a
mpf_add(Halley_temp1,Halley_temp1,Halley_temp2); 	// Halley_temp1= Halley_temp1 + temp2
mpf_mul(Halley_temp2,xn,xn);						// Halley_temp2= xn * xn
mpf_mul(Halley_temp2,Halley_temp2,xn);				// Halley_temp2=Halley_temp2 * xn
mpf_mul(Halley_temp2,Halley_temp2,value_two); 		//Halley_temp2= Halley_temp2 * value_two
mpf_add(Halley_temp2,Halley_temp2,a);        		//Halley_temp2 = Halley_temp2 + a;
mpf_div(xn_1,Halley_temp1,Halley_temp2);			// xn_1= Halley_temp1/temp2
mpf_mul(xn_1,xn_1,xn);								//xn_1= xn_1 * xn
 

if(mpf_cmp(xn_1,xn)==0)		
{
       mpf_set(xn,xn_1);
       return;
}

 
mpf_add(xn,xn_1,value_zero);
}
}
