#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const
{
    return data.size();
}

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    /***** Complete this function. *****/
    data.push_front(Node(value));
}

void SortedList::append(const long value)
{
    /***** Complete this function. *****/
    data.push_back(Node(value));
}

void SortedList::remove(const int index)
{
    list<Node>::iterator it = data.begin();

    for(int i=0; i< index ; i++)
    {
        it++;
    }
    data.erase(it);
}

void SortedList::insert(const long value)
{

    list<Node>::const_iterator it = data.begin();
    if(data.size()==0)
    {
        data.push_back(Node(value));
    }
    else
    {
        list<Node>::const_iterator it = data.begin();
        while ((it!=data.end())&& (it->get_value() < value))
        {
            it++;
        }
        if(it==data.end())
            data.push_back(Node(value));
        else
            data.insert(it,Node(value));
    }
}

Node SortedList::at(const int index)
{
    list<Node>::iterator it =data.begin();
    for(int i=0;i<index;++i)
        ++it;
    return *it;
}
