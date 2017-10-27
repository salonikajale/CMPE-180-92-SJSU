//HEADER FILES
#ifndef BOOKNODE_H_
#define BOOKNODE_H_
#include "Book.h"

class BookNode
{
public:
    BookNode();     //Default constructor
    BookNode(Book book);    //Paramaterized constructor
    //Getter functions
    Book get_book() const;  //Function to get book
    BookNode* get_next() const; //Function to get next Book
    void set_next(BookNode *next);  //Function to set the next Book
private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */
