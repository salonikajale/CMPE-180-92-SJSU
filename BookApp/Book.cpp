#include <string>
#include <iostream>
#include "Book.h"

using namespace std;

//Definition for default constructor
Book :: Book(): isbn(""), last(""), first(""), title("")
{

}
//Definition for parametirized constructor
Book :: Book(string isbn, string last, string first, string title): isbn(isbn), last(last), first(first), title(title)//Parameterized constructor
{

}

//Definition for Destructor
Book :: ~Book()
{

}

//Getter function for isbn
string Book::get_isbn()const
{
    return isbn;
}
//Getter function for last name
string Book::get_last() const
{
    return last;
}
//Getter function for first name
string Book::get_first() const
{
    return first;
}

//Getter function for title
string Book::get_title() const
{
    return title;
}

//Function definition for extraction operator
ostream& operator <<(ostream& os,const Book& book1 )
{

    os << "Book{ISBN=" << book1.isbn << ", last=" << book1.last<< ", first=" << book1.first << ", title=" << book1.title << "}";
    return os;

}

//Function definition for insertion operator
istream& operator >>(istream& ins, Book& book2 )
{
    getline(ins, book2.isbn,',');
    getline(ins, book2.last,',');
    getline(ins, book2.first,',');
    getline(ins, book2.title);
    return ins;
}
