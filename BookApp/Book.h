//Header files
#include <string>
#include <fstream>
#ifndef BOOK_H_
#define BOOK_H_
using namespace std;

class Book
{
public:
    Book();					                                     //default constructor
    Book(string isbn, string last, string first, string title);	//Paramaterized constructor
    ~Book();													//Destructor

    //Getter functions
    string get_isbn() const;											//isbn getter function
    string get_last() const;											//last getter function
    string get_first() const;											//first getter function
    string get_title() const;											//title getter function

    //Overloading the insertion ad extraction operators
    friend ostream& operator <<(ostream& out,const Book& book1 );			//operator overloading for ostream
    friend istream& operator >>(istream& out, Book& book2 );				//operator overloading for istream

private:
    //variable declaration
    string isbn;
    string last;
    string first;
    string title;
};

#endif /* BOOK_H_ */
