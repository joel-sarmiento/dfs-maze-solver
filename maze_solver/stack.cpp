/*
 * file: stack.cpp
 * author: Joel Sarmiento
 *
 * This file contains the implementations of the LocationStack and
 * LocationStackNode classes
 */

#include "stack.h"
#include <vector>


/*
 * LocationStack
 *
 * This constructor sets the top of the stack to null
 *
 * Parameters: none
 *
 * Return value: none
 */
LocationStack::LocationStack() {
    top = nullptr;
}


/*
 * ~LocationStack
 *
 * This function is the destructor that frees any allocated memory
 *
 * Parameters: none
 *
 * Return value: none
 */
LocationStack::~LocationStack() {
    if (!isEmpty()) {
        delete top;
    }
}


/*
 * push
 *
 * This function pushes a location to the top of the stack
 *
 * Parameters:
 *     loc: a location to be pushed onto the stack
 *
 * Return value: none
 */
void LocationStack::push(const Location &loc) {
    top = new LocationStackNode(loc, top);
}


/*
 * pop
 *
 * This function removes a location from the top of the stack
 *
 * Parameters: none
 *
 * Return value: none
 */
void LocationStack::pop() {
    assert(!isEmpty());
    LocationStackNode *temp = top;
    top = top->getNextNode();
    temp->setNextNode(nullptr);
    delete temp;
}


/*
 * getTop
 *
 * This function returns the location at the top of the stack
 *
 * Parameters: none
 *
 * Return value: none
 */
const Location &LocationStack::getTop() const {
    assert(!isEmpty());
    return top->getLocation();
    
}


/*
 * isEmpty
 *
 * This function checks if the stack is empty
 *
 * Parameters: none
 *
 * Return value: true if empty, otherwise returns false
 */
bool LocationStack::isEmpty() const {
    return (top == nullptr);
}


/*
 * isOn
 *
 * This function returns true if the given Location is on the stack,
 * otherwise returns false.
 *
 * Parameters:
 *     loc: a location to be checked if it is on the stack
 *
 * Return value: true if location is on the stack, otherwise returns false
 */
bool LocationStack::isOn(const Location &loc) const {
    LocationStackNode *current = top;
    
    while (current != nullptr) {
        if (current->getLocation() == loc) {
            return true;
        }
        current = current->getNextNode();
    }
    return false;
}


/*
 * operator<<
 *
 * This function streams out the stack from bottom to top.
 *
 * Parameters:
 *     os: a means of streaming out the stack
 *
 * Return value: a reference to the stream for chaining purposes
 */
ostream &operator<<(ostream &os, const LocationStack &s) {
    LocationStackNode *current = s.top;
    vector<Location> locations;
    
    // Traverse stack from top to bottom
    while(current) {
        locations.push_back(current->getLocation());
        current = current->getNextNode();
    }
    
    // Print locations bottom to top
    for(auto it = locations.rbegin(); it != locations.rend(); ++it) {
        os << *it << endl;
    }
    
    return os;
}


/*
 * LocationStackNode
 *
 * This constructor takes values to initialize the location and next node
 *
 * Parameters:
 *     loc: a location to initialize a node
 *     next: pointer to next node on the stack
 *
 * Return value: none
 */
LocationStackNode::LocationStackNode(const Location &loc, LocationStackNode *next) {
    location = loc;
    nextNode = next;
}


/*
 * ~LocationStackNode
 *
 * This destructor calls delete on the nextNode, so that deleting
 * the top of the stack has a chaining effect that deletes every node
 * on the stack.
 *
 * Parameters: none
 *
 * Return value: none
 */
LocationStackNode::~LocationStackNode() {
    if (nextNode) {
        delete nextNode;
    }
}


/*
 * getLocation
 *
 * This function returns the location of a node
 *
 * Parameters: none
 *
 * Return value: location of a node
 */
const Location &LocationStackNode::getLocation() const {
    return location;
}


/*
 * getNextNode
 *
 * This function gets the next node
 *
 * Parameters: none
 *
 * Return value: next node in the stack
 */
LocationStackNode *LocationStackNode::getNextNode() const {
    return nextNode;
}


/*
 * setNextNode
 *
 * This function is our interface for modifying nodes as necessary
 *
 * Parameters:
 *     next: the node to be assigned as the next node of another node
 *
 * Return value: none
 */
void LocationStackNode::setNextNode(LocationStackNode *next) {
    nextNode = next;
}
