/*
 * file: driver.cpp
 * author: Joel Sarmiento
 *
 * This file is the driver that solves a given maze using DFS
 */

#include <iostream>
#include "location.h"
#include "stack.h"
#include "maze.h"

using namespace std;

/*
 * main
 *
 * This is the driver that uses DFS and a stack to solve a given maze
 *
 * Parameters:
 *     argc: the number of arguments from the command line
 *     argv: the command line argument values
 *
 * Return value: 0, meaning the program executed successfully
 */
int main(int argc, char **argv) {
    Maze maze;
    Location startLocation;
    LocationStack stack;
    
    // Read maze from input
    cin >> maze;
    startLocation = maze.getStartLocation();

    // Initialize iterator for neighbor locations
    startLocation.iterationBegin();
    
    stack.push(startLocation);

    Location current = stack.getTop();
    current.iterationBegin();
    Location neighbor = current.iterationCurrent();
    
    // Begin depth-first search
    while (!stack.isEmpty() && !maze.isEndLocation(stack.getTop())) {
        neighbor.iterationBegin();

        // If all neighbors of current location have been visited
        if (current.iterationDone()) {
            stack.pop();

            // If stack is not empty after popping, resume from new top
            if (!stack.isEmpty()) {
                current = stack.getTop();
                neighbor = current.iterationCurrent();
            }
        } else {
            neighbor = current.iterationCurrent();

            stack.pop(); // Pop current location to update iterator
            current.iterationAdvance();
            stack.push(current); // Push updated location back on
            
            // If neighbor is a valid, unexplored location
            if (maze.isValidLocation(neighbor) && !stack.isOn(neighbor)) {
                stack.push(neighbor);
                current = stack.getTop();
                current.iterationBegin();
            }
        }
    }
    
    // Output solution or no solution
    if (stack.isEmpty()) {
        cout << "No solution" << endl;
    } else {
        cout << "Solution found" << endl;
        cout << stack;
    }
    
    
    return 0;
}

// --Testing functions used--

/*
void constructorTest() {
    Location loc;
    
    cout << "Testing constructor..." << endl;
    cout << "Expected output: " << "0 0" << endl;
    cout << "Test output: " << loc << endl << endl;
}

void operatorTests() {
    Location loc1, loc2, loc3;
    
    cout << "Testing operators..." << endl;
    cout << "Enter location: ";
    cin >> loc1;
    cout << "Location entered: " << loc1 << endl;
    
    cout << "Enter two locations to compare: ";
    cin >> loc2 >> loc3;
    
    if (loc2 == loc3) {
        cout << "Equal" << endl;
    } else {
        cout << "Not equal" << endl;
    }
    cout << endl;
}

void iterationTests() {
    Location loc;
    
    loc.iterationBegin();
    cout << "Neighbors of location 0 0: " << endl;
    for (loc.iterationBegin(); !loc.iterationDone(); loc.iterationAdvance()) {
        Location neighbor = loc.iterationCurrent();
        cout << neighbor << endl;
    }
}


void LocationStackTests() {
    LocationStack s;
    Location loc1, loc2;
    
    //input locations
    cout << "Input two locations: ";
    cin >> loc1 >> loc2;
    
    //testing isEmpty()
    cout << "Testing isEmpty()... ";
    if (s.isEmpty()) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }
    
    //testing push()
    cout << "Pushing loc1..." << endl;
    s.push(loc1);
    cout << "Updated top: " << s.getTop() << endl << endl;
    
    cout << "Pushing loc2..." << endl;
    s.push(loc2);
    cout << "Updated top: " << s.getTop() << endl << endl;
    
    
    //testing isOn()
    Location loc3;
    cout << "Input a location: ";
    cin >> loc3;
    
    cout << "Is location on stack? ";
    if (s.isOn(loc3)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    
    //testing pop()
    cout << "Popping loc2..." << endl;
    s.pop();
    
    cout << "Popping loc1..." << endl;
    s.pop();
    
    cout << "Stack should be empty...";
    if (s.isEmpty()) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }
}

void MazeTests() {
    Maze m;
    Location loc1;
    
    //testing operator>>
    cout << "Enter maze: " << endl;
    cin >> m;
    
    //testing getStartLocation
    cout << "Start location: " << m.getStartLocation() << endl;
    cout << endl;
    
    //testing isValidLocation
    cout << "Enter a location...";
    cin >> loc1;
    cout << "Is this a valid location? ";
    if (m.isValidLocation(loc1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << endl;
    
    //testing isEndLocation
    Location loc2;
    
    cout << "Enter a location...";
    cin >> loc2;
    cout << "Is this the end location? ";
    if (m.isEndLocation(loc2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
}
*/
