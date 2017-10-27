#include <iostream>
#include "Node.h"

using namespace std;

//Accessing static data members and setting initial value to 0
long Node::constructor_count=0;
long Node:: copy_count=0;
long Node::destructor_count=0;


//Constructor
Node::Node(const long the_value) {
    constructor_count++;
    value=the_value;
}

//Copy Constructor
Node::Node(const Node &other) {
    value=other.value;
    copy_count++;
}

//Destructor
Node::~Node() {
    destructor_count++;
}

//Getter method for getting the value
long Node::get_value() const {
    return  value;

}

//Getter for constructor count
long Node::get_constructor_count() {
    return constructor_count;

}

//Getter to get the copy count
long Node::get_copy_count() {
    return copy_count;

}

//Getter to get the destructor count
long Node::get_destructor_count() {

    return destructor_count;

}

//Method to reset all the counts
void Node::reset() {
    constructor_count=0;
    copy_count=0;
    destructor_count=0;

}

//Method to check if the 2 values are equal
bool  Node::operator==(const Node &other) const {
    if(this->value== other.value)
        return true;
    else
        return false;

}

//Method to overload > operator
bool Node::operator > (const Node &other) const {
    if(this->value > other.value)
        return true;
    else
        return false;
}

//Method to overload < operator
bool Node::operator < (const Node& other) const{
    if(this->value < other.value)
        return true;
    else
        return false;

}