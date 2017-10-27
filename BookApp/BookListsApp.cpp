//HEADER FILES
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "BookNode.h"
#include "BookList.h"
using namespace std;

const string CATEGORIES_FILE_NAME = "categories.txt"; //File categories.txt is declared as a constant
int main()
{
    ifstream input;
    input.open(CATEGORIES_FILE_NAME.c_str()); //Open the file categories.txt
    cout <<endl;
      
    string cat;               //creating a string category   
    vector<string> categories;      //Create a vector of categories
    vector<BookList> list;          //Create a vector of BookList

    BookList list_merge("MERGED");
    BookList list_AtoM("AUTHORS A-M");
    BookList list_NtoZ("AUTHORS N_Z");

    while(input >> cat)
    {
        categories.push_back(cat);
        ifstream input1;
        input1.open((cat + ".txt").c_str());

        BookList list1(cat); 
        Book book;
        while(input1 >> book)
        {
            list1.insertBook(book);
            list_merge.insertBook(book);
            if(book.get_last()[0] <= 'M') //condition to check if the last name start from A to M
            {
                list_AtoM.insertBook(book);  //if yes then insert into the list AtoM

            }
            else
            {
                list_NtoZ.insertBook(book); //if  not then insert in the list from NtoZ
            }

        }
        list.push_back(list1); //add a new element at the  end of the list
        list1.print();   //print the list 1
        input1.close(); //close the input file
    }

    input.close(); //close the input file
    list_merge.print(); //print the merge list
    list_AtoM.print(); //print the list from AtoM
    list_NtoZ.print();//Print the list from NtoZ
    return 0;
}


