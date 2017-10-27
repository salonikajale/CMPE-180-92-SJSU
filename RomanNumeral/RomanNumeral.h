//HEADER FILES
#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <string>
using namespace std;

class RomanNumeral
{
	
private:
	int decimal;  	 //Declaring private member variable decimal
   string roman; 	 //Declaring private member variable roman     
   void to_roman();  //Declaring private method toRoman
   void to_decimal();//Declaring private method toDecimal
    
    
public:
   RomanNumeral();		 		  // Declaring default constructor
   RomanNumeral(string roman);	 //Declaring parametrized constructor taking string argument
   RomanNumeral(int num);		//Declaring parametrized constructor taking integer argument
   ~RomanNumeral();		    //Declaring destructor

	//Declaring getter methods decimal and roman
	int getDecimal() const;
   string getRoman() const;
   

    // Overloading arithmetic operators +,-,*,/
    RomanNumeral operator +(const RomanNumeral& value);
    RomanNumeral operator -(const RomanNumeral& value);
    RomanNumeral operator *(const RomanNumeral& value);
    RomanNumeral operator /(const RomanNumeral& value);

    // Overloading equality operators == , !=
    bool operator ==(const RomanNumeral& value);
    bool operator !=(const RomanNumeral& value);

    // Overloading input and output operators stream >> and << operators
    friend istream& operator >>(istream& input, RomanNumeral& number);
    friend ostream& operator <<(ostream& output, const RomanNumeral& number);

};

#endif /* ROMANNUMERAL_H_ */

