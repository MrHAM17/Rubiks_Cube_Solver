// main.cpp
#include <iostream>
#include "RubiksCube.h"

int main() {
    std::cout << "Welcome to Rubik's Cube Simulator!\n";

    RubiksCube cube;
    cube.displayCube();

    // Example: Move the front face clockwise
    cube.moveFrontClockwise();
    cube.displayCube();

    // Add more cube manipulation logic based on user input

    return 0;
}
