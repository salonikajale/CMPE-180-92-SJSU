#include <string>
#include<iostream>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

//Insert new nodes at the beginning of the data vector.

void vector_prepends(SortedVector& sv, const int size)
{
   sv.reserve(size);
    for(int i=size-1;i>=0;i--)
        sv.prepend(i);
}

//Test function: Insert new nodes at the beginning of the data list.
void list_prepends(SortedList& sl, const int size)
{
    for(int i=size-1;i>=0;i--)
        sl.prepend(i);
}

//Test function: Append new nodes at the end of the data vector.
void vector_appends(SortedVector& sv, const int size)
{
    for(int i=0;i<size;i++)
        sv.append(i);
}

//* Test function: Append new nodes at the end of the data list.
void list_appends(SortedList& sl, const int size)
{
    for(int i=0;i<size;i++)
        sl.append(i);
}

//Access nodes in the data vector.
void vector_gets(SortedVector& sv, const int size) throw (string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand() %size;
        long value = sv.at(index).get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

//Access nodes in the data list
void list_gets(SortedList& sl, const int size) throw (string)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {

        int index = rand()%size;
        long value=sl.at(index).get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}


void vector_removes(SortedVector& sv, const int size)
{
    vector_appends(sv, size);
    Node::reset();
    // Loop to remove a node at a random position
    // one at a time until the nodes are all gone.
    while (sv.size() > 0)
    {
        int index = rand()%sv.size();
        sv.remove(index);
    }
}


void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();
    while (sl.size() > 0)
    {

        int index = rand()%sl.size();
        sl.remove(index);
    }
}

//Test function: Insert random values into the sorted data vector
void vector_inserts(SortedVector& sv, const int size)
{

    sv.reserve(size);
    for(int i=0;i<size;i++) {
        long value=rand();
        sv.insert(value);
    }
}

//Test function: Insert random values into the sorted data list.
void list_inserts(SortedList& sl, const int size)
{
    for(int i=0;i<size;i++) {
        long value = rand();
        sl.insert(value);
    }
}



