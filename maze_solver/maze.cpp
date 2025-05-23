/*
 * file: maze.cpp
 * author: Joel Sarmiento
 *
 * This file contains the implementations of the Maze class methods
 */

#include "maze.h"


/*
 * Maze
 *
 * This constructor initializes the data members
 *
 * Parameters: none
 *
 * Return value: none
 */
Maze::Maze() {
    validLocationCount = 0;
    validLocations = new Location[validLocationCount];
}


/*
 * ~Maze
 *
 * This destructor frees any memory that the object is using
 *
 * Parameters: none
 *
 * Return value: none
 */
Maze::~Maze() {
    delete[] validLocations;
}


/*
 * getStartLocation
 *
 * This function returns the start location of the maze
 *
 * Parameters: none
 *
 * Return value: start location of maze
 */
Location Maze::getStartLocation() const {
    return startLocation;
}


/*
 * isValidLocation
 *
 * This function iterates through the valid locations of the maze to see if
 * a given location is valid
 *
 * Parameters:
 *     loc: a location that is checked to see if it is valid
 *
 * Return value: true if location is valid, false if otherwise
 */
bool Maze::isValidLocation(const Location &loc) const {
    // Iterate through array
    for (int i = 0; i < validLocationCount; ++i) {
        // Return true if loc is found
        if (validLocations[i] == loc) {
            return true;
        }
    }
    
    return false;
}


/*
 * isEndLocation
 *
 * This functions checks to see if a given location is the end location
 *
 * Parameters:
 *     loc: a location that is checked to see if it is the end location
 *
 * Return value: true if the location is the end location, false if otherwise
 */
bool Maze::isEndLocation(const Location &loc) const {
    return (loc == endLocation);
}


/*
 * operator>>
 *
 * This streams in a maze
 *
 * Parameters:
 *     is: a means of streaming in a maze
 *     m: a given maze to be solved
 *
 * Return value: a reference to the stream for chaining purposes
 */
istream &operator>>(istream &is, Maze &m) {
    // Allocate array using input location count
    is >> m.validLocationCount;
    delete[] m.validLocations;
    
    m.validLocations = new Location[m.validLocationCount];
    
    // Stream in maze locations
    for (int i = 0; i < m.validLocationCount; ++i) {
        is >> m.validLocations[i];
    }
    
    // Stream in start and end locations
    is >> m.startLocation >> m.endLocation;
    
    return is;
}

