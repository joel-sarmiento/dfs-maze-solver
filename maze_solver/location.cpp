/*
 * file: location.cpp
 * author: Joel Sarmiento
 *
 * This file contains the implementations of the Location methods
 */

#include "location.h"

/*
 * Location
 *
 * This is the Location constructor that initializes the row and column
 * data members to a reasonable starting value and sets the nextDirection to
 * the right to prepare for exploration, prioritizng the right direction
 *
 * Parameters: none
 *
 * Return value: none
 */
Location::Location() {
    row = 0;
    col = 0;
    nextDirection = RIGHT;
}


/*
 * iterationBegin
 *
 * This method initializes the iteration capability of a Location object
 *
 * Parameters: none
 *
 * Return value: none
 */
void Location::iterationBegin() {
    nextDirection = RIGHT;
}


/*
 * iterationCurrent
 *
 * This method creates a copy of the current Location object, modifies the
 * copy so that it represents a different location (either in row or column),
 * and it returns the neighbor it created.
 *
 * Parameters: none
 *
 * Return value: neighbor location
 */
Location Location::iterationCurrent() const {
    Location neighbor = *this;
    
    if (nextDirection == RIGHT) {
        neighbor.col += 1;
    }
    if (nextDirection == DOWN) {
        neighbor.row += 1;
    }
    if (nextDirection == LEFT) {
        neighbor.col -= 1;
    }
    if (nextDirection == UP) {
        neighbor.row -= 1;
    }
    
    return neighbor;
}


/*
 * iterationAdvance
 *
 * This method moves the iteration forward, so that the next time
 * iterationCurrent() is called, it returns a different neighbor
 *
 * Parameters: none
 *
 * Return value: none
 */
void Location::iterationAdvance() {
    nextDirection++;
}


/*
 * iterationDone
 *
 * This method returns true when the all the neighbors of a Location
 * have been iterated over.
 *
 * Parameters: none
 *
 * Return value: none
 */
bool Location::iterationDone() const {
    return (nextDirection == DONE);
}


/*
 * operator==
 *
 * This function compares two Location objects
 *
 * Parameters:
 *     loc: a location to be compared
 *
 * Return value: true if equal, false if not
 */
bool Location::operator==(const Location &loc) const {
    return ((row == loc.row) && (col == loc.col));
}


/*
 * operator<<
 *
 * This method provides a means of streaming a Location object out
 *
 * Parameters:
 *     os: a means of streaming out a location
 *     loc: a location to be output
 *
 * Return value: the given stream
 */
ostream &operator<<(ostream &os, const Location &loc) {
    os << loc.row << " " << loc.col;
    return os;
}


/*
 * operator>>
 *
 * This method provides a means of streaming a Location object in
 *
 * Parameters:
 *     is: a means of streaming in a location
 *     loc: a location to be input
 *
 * Return value: a reference to the given stream for chaining purposes
 */
istream &operator>>(istream &is, Location &loc) {
    is >> loc.row >> loc.col;
    return is;
}
