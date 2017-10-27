//Header files
#include <iostream>
#include <fstream>
#include <string>
#include "RomanNumeral.h" //Including the header file

using namespace std;

//Default contructor
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
	//roman is assigned null string
	//decimal is assigned value 0
}

//Constructor taking an integer value
RomanNumeral::RomanNumeral(int num) : decimal(num)
{
    //Compute the Roman numeral string.
    to_roman();
}

//Constructor taking a string value
RomanNumeral::RomanNumeral(string input_string) : roman(input_string)
{
    // Compute the decimal num.
    to_decimal();
}

//Destructor
RomanNumeral::~RomanNumeral()
{
	// Used to free memory
}

//Getter method for Romans
string RomanNumeral::getRoman() const
{
    return roman;
}

//Getter method for Decimal
int RomanNumeral::getDecimal() const
{
    return decimal;
}

//Overloading the operator +
RomanNumeral RomanNumeral::operator +(const RomanNumeral& value)
{
   int result = decimal + value.decimal;
   RomanNumeral add(result);
   return add;
}

//Overloading the operator -
RomanNumeral RomanNumeral::operator -(const RomanNumeral& value)
{
    int result = decimal - value.decimal;
    RomanNumeral subtract(result);
    return subtract;
}

//Overloading the operator *
RomanNumeral RomanNumeral::operator *(const RomanNumeral& value)
{
    int result = decimal*value.decimal;
    RomanNumeral multiplication(result);
    return multiplication;
}

//Overloading the operator /
RomanNumeral RomanNumeral::operator /(const RomanNumeral& value)
{
    int result = decimal/value.decimal;
    RomanNumeral division(result);
    return division;
}

//Overloading the operator ==
bool RomanNumeral::operator ==(const RomanNumeral& value)
{
    return decimal == value.decimal;
}


//Overloading the operator !=
bool RomanNumeral::operator !=(const RomanNumeral& value)
{
    return decimal != value.decimal;
}


//Overloading the operator >>
istream& operator >>(istream& input, RomanNumeral& number)
{
    string input_str;
    input >>input_str;
    number.roman = input_str;
    number.to_decimal();
    return input;
}

//Overloading the operator <<
ostream& operator <<(ostream& output, const RomanNumeral& number)
{
    output << "[" << number.decimal << ":" << number.roman << "]";
    return output;
}


//Function to convert integer to roman
void RomanNumeral::to_roman()
{
    int temp = decimal;
    roman = "";
	for(int i=temp; i>=1000; i=i-1000){
		roman+="M";
		temp=temp-1000;
	}

    if (temp >= 900)
    {
        roman += "CM";
        temp -= 900;
    }
    else if (temp >= 500)
    {
        roman += "D";
        temp -= 500;
    }
    else if (temp >= 400)
    {
        roman += "CD";
        temp -= 400;
    }
    
    for(int i=temp;i>=100;i=i-100){
		roman+="C";
		temp=temp-100;
	}

    if (temp >= 90)
    {
        roman += "XC";
        temp -= 90;
    }
    else if (temp >= 50)
    {
        roman += "L";
        temp -= 50;
    }
    else if (temp >= 40)
    {
        roman += "XL";
        temp -= 40;
    }
	for(int i=temp;i>=10;i=i-10){
		roman+="X";
		temp-=10;
	}
	

    if (temp >= 9)
    {
        roman += "IX";
        temp -= 9;
    }
    else if (temp >= 5)
    {
        roman += "V";
        temp -= 5;
    }
    else if (temp >= 4)
    {
        roman += "IV";
        temp -= 4;
    }
	for(int i=temp;i>=1;i=i-1){
		roman+="I";
		temp-=1;
	}
	
}

//Function to convert Roman to decimal
void RomanNumeral::to_decimal()
{
    int length = roman.length();
    decimal = 0;


    for (int i = 0; i < length; i++)
    //while(i < length )
    {
        switch (roman[i])
        {
            case 'M':
                decimal += 1000;
                break;

            case 'D':
                decimal += 500;
                break;

            case 'C':
                if (i+1 < length)
                {
                    switch (roman[i+1])
                    {
                        case 'D':  // CD
                            decimal += 400;
                            i++;
                            break;

                        case 'M':  // CM
                            decimal += 900;
                            i++;
                            break;

                        default:
                            decimal += 100;
                            break;
                    }
                }
                else decimal += 100;
                break;

            case 'L':
                decimal += 50;
                break;

            case 'X':
                if (i+1 < length)
                {
                    switch (roman[i+1])
                    {
                        case 'L':  // XL
                            decimal += 40;
                            i++;
                            break;

                        case 'C':  // XC
                            decimal += 90;
                            i++;
                            break;

                        default:
                            decimal += 10;
                            break;
                    }
                }
                else decimal += 10;
                break;

            case 'V':
                decimal += 5;
                break;

            case 'I':
                if (i+1 < length)
                {
                    switch (roman[i+1])
                    {
                        case 'V':  // IV
                            decimal += 4;
                            i++;
                            break;

                        case 'X':  // IX
                            decimal += 9;
                            i++;
                            break;

                        default:
                            decimal++;
                            break;
                    }
                }
                else decimal++;
                break;
        }
    }
}


