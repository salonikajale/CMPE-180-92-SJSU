#include <iostream>
#include <iterator>
#include "SortedVector.h"
#include "Node.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const {
    return data.size();
}

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }
    return it == data.end();  // Good if reached the end.
}

void SortedVector::reserve(const int size)
{
    data.reserve(size);
}
void SortedVector::prepend(const long value)
{
    /***** Complete this function. *****/
    vector<Node>::const_iterator it = data.begin();
    data.insert(it,Node(value));
}

void SortedVector::append(const long value)
{
    data.push_back(Node(value));
}

void SortedVector::remove(const int index)
{
    /***** Complete this function. *****/
    vector<Node>::iterator it = data.begin();

    for(int i=0; i< index ; i++)
    {
        it++;
    }
    data.erase(it);
}

void SortedVector::insert(const long value)
{
    /***** Complete this function. *****/
    vector<Node>::const_iterator it = data.begin();
    if(data.size()==0)
    {
        data.push_back(Node(value));
    }
    else
    {
        while ((it!=data.end())&& (it->get_value()<value))
        {
            it++;
        }
        if(it==data.end())
            data.push_back(Node(value));
        else
            data.insert(it,Node(value));
    }
}

Node SortedVector::at(const int index) const
{

    return data.at(index);
}
