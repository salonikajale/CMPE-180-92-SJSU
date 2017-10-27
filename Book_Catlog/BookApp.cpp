
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Book.h"

/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};


/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const vector<Book>& catalog,const string isbn);
void search_book(const vector<Book>& catalog, const string to_search);
void remove_book(vector<Book>& catalog,const string isbn);
void add_book(vector<Book>& catalog,const Book& B);
const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog

    char command;

    /**
     * Loop to read commands until the end of file.
     */
    int times =0;
    cout<<"\n";
    while (!input.fail())
    {
        char oper;
        input >> oper;
        if (oper == '+') {
            Book b;
            input >> b;
			add_book(catalog,b);
			cout<<"\n";
		}
        else if (oper == '-') {
			string isbn_toremove;
			getline(input, isbn_toremove);
			remove_book(catalog,isbn_toremove.substr(1,isbn_toremove.length()-1));
			cout<<"\n";
		}
		
        else if ((oper == '?')){
			if((times>9))
				break;
			string to_extract;
			getline(input, to_extract);
			search_book(catalog,to_extract);
			cout<<"\n";times++;
		}
		else {
			cout << oper << " *** Invalid command ***" << endl;
			string dummy;
			getline(input,dummy);
			cout<<"\n";
		}
		
        }

    return 0;
}


int find(const vector<Book>& catalog,const string isbn)
{
	int beg = 0;
	int end = catalog.size()-1;
	int mid;
	while(beg<=end)
	{
		mid = (beg+end)/2;
		if(catalog[mid].getIsbn() == isbn)
			return mid;
		else if(catalog[mid].getIsbn() > isbn)
			end = mid-1;
		else if(catalog[mid].getIsbn() < isbn)
			beg = mid+1;

	}

	return -1;
}

void add_book(vector<Book>& catalog,const Book& B)
{
	if(catalog.size()==0)
	{
		catalog.push_back(B);
		cout << "+ Inserted at index 0: " << B;

	}
	else
	{
		int loc = -1;
		for(int i=0;i<catalog.size();i++)
		{
			if(catalog[i].getIsbn() >= B.getIsbn())
			{
				loc = i;
				break;
			}
		}
		if(loc==-1)
		{
			cout << "+ Inserted at index "<< catalog.size() <<": " << B;
			catalog.push_back(B);
		}
		else
		{
			if(catalog[loc].getIsbn() == B.getIsbn())
			{
				cout<<"+ Inserted at index "<<loc<<": "<<B;
				cout<<"*** Duplicate ISDN ***\n";
			}
			else
			{
				catalog.insert(catalog.begin() + loc,B);
				cout << "+ Inserted at index "<< loc <<": " << B;
			}
		}
	}

}

void remove_book(vector<Book>& catalog,const string isbn)
{
	int rem_index = find(catalog,isbn);
	if(rem_index == -1)
	{
		Book B(isbn,"","","","");
		cout<<"- Removed "<<B;
		cout<<"*** Book not found ***\n";
	}
	else
	{
		cout<<"- Removed "<<catalog[rem_index];
		catalog.erase(catalog.begin() + rem_index);
	}

}

void search_book(const vector<Book>& catalog, const string to_search)
{
	cout<<"? ";
	if(to_search == "")
	{
		cout << "All books in the catalog:\n";
		for(int i=0;i<catalog.size();i++)
			cout<<catalog[i];
	}
	else
	{
		string entity;
		string value;
		string dem = "=";
		entity = to_search.substr(0,to_search.find(dem));
		value = to_search.substr(to_search.find(dem) + dem.length(),to_search.length()- to_search.find(dem) - dem.length());
		if(entity.find("author")!=-1)
		{
			cout<<"Books by author "<<value<<":\n";
			for(int i=0;i<catalog.size();i++)
			{
				if(catalog[i].getAuthor() == value)
					cout<<catalog[i];
			}
		}
		else if(entity.find("category")!=-1)
		{
			cout<<"Books in category "<<value<<":\n";
			for(int i=0;i<catalog.size();i++)
			{
				if(catalog[i].getCategory() == value)
					cout<<catalog[i];
			}
		}
		else if(entity.find("isbn")!=-1)
		{
			cout<<"Book with ISBN "<<value<<":\n";
			for(int i=0;i<catalog.size();i++)
			{
				if(catalog[i].getIsbn() == value)
					cout<<catalog[i];
			}
		}
	}

}
