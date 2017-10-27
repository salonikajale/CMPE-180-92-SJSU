#include <string>
#include <iostream>
#include "BookNode.h"
using namespace std;

//Definition for default constructor
BookNode :: BookNode(): next(nullptr)
{

}

//Definition of Parameterized constructor
BookNode :: BookNode(Book book): book(book), next(nullptr)
{
    
}

//Definition for fetching a book
Book BookNode:: get_book() const
{
    return book;
}

//Definition to get next for Book
BookNode* BookNode :: get_next() const
{
    return next;
}
//Defintion to set next for book
void BookNode:: set_next(BookNode *next)
{
    this->next = next;
}