//Header files
#include <string>
#include <iostream>
#include "BookList.h"
#include "BookNode.h"

using namespace std;

//Definition for Default constructor
BookList ::BookList(): name(""), head(nullptr), tail(nullptr)
{

}

//Definition for Parametrized constructor
BookList:: BookList(const string name): name(name), head(nullptr), tail(nullptr)
{
    create();
}

//Definition to get the name of the Book
string BookList :: get_name() const
{
    return name;
}

//Definition to get head
BookNode* BookList:: get_head() const
{
    return head;
}

//Definition to get tail
BookNode* BookList:: get_tail() const
{
    return tail;
}

//Definition for printing
void BookList::print()
{
    cout << "Book list: "<< get_name() <<"\n\n";

    BookNode *current;
    current = head;
    int count=0;

    while( current != nullptr)
    {
        cout <<	"  "<< (*current).get_book() << "\n";

        current = current->get_next();
        count++;
    }
    cout << "    ("<< count << " books"<< ")"<< "\n\n";
}


//Definition to create a Node//Empty definition
void BookList:: create()
{

}

//Function for inserting a Book
void BookList:: insertBook(Book b)
{
    BookNode *booknode=new BookNode(b); //creating an object of Book node
    string is = b.get_isbn();
    if(head == nullptr )        //Check if head is equal to a null pointer
    {
        head = booknode;
        tail = booknode;
    }
    else
    {
        BookNode *curr;
        curr = head;
        BookNode *prev= nullptr;

        while( curr != nullptr)
        {
            Book temp;
            temp = (*curr).get_book();
            if(temp.get_isbn() == is)
            {
                break;
            }
            if(temp.get_isbn() > is)
            {
                if(prev == nullptr)
                {
                  head = booknode;
                  booknode->set_next(curr);
                }
                else
                {
                    prev->set_next(booknode);
                    booknode->set_next(curr);
                }
                break;
            }
            else if(curr->get_next() == nullptr)
            {
                curr->set_next(booknode);
                break;
            }

            prev = curr;
            curr= curr->get_next();
        }
    }
}
