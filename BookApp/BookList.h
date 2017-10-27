#include "BookNode.h"
#include <string>
#ifndef BOOKLIST_H_
#define BOOKLIST_H_


using namespace std;
class BookList
{
public:
    BookList();						//default constructor
    BookList(const string name);	//Parametrized constructor

    //Getter functions
    string get_name() const;         //Function for get name
    BookNode*  get_head() const;    //Function to get head
    BookNode*  get_tail() const;   //Function to get tail

    void print();                   //Print function
    void insertBook(Book b);       //Function to insert a  Book

private:
    string name;       // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes
    void create();   //Function for creating a node
};

#endif /* BOOKLIST_H_ */
