// g++ main.cpp rubik_solver.cpp -o main
// .\main

#include "rubik_solver.h"  // Include the header file
#include "rubik_solver.cpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for std::find

// Function to convert a string to uppercase
std::string toUpper(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(c);
    }
    return result;
}

// Function to validate color input
bool isValidColor(const std::string& color) {
    // List of valid colors (you can customize this list)
    std::vector<std::string> validColors = {"W", "Y", "B", "G", "R", "O"};

    // Convert color to uppercase for case-insensitive comparison
    std::string upperColor = toUpper(color);

    // Check if the entered color is in the list of valid colors
    return std::find(validColors.begin(), validColors.end(), upperColor) != validColors.end();
}

// Function to get a valid color input
std::string getValidColorInput() {
    std::string color;
    do {
        std::cout << "Enter a valid color: ";
        std::cin >> color;

        // Convert color to uppercase for case-insensitive comparison
        std::string upperColor = toUpper(color);

        if (!isValidColor(upperColor)) {
            std::cout << "Invalid color. Please enter a valid color.\n";
        }
    } while (!isValidColor(toUpper(color)));

    return toUpper(color);
}

// Function to display a welcome message
void displayWelcomeMessage() {
    std::cout << "\n\n\n******************* Welcome to the Rubik's Cube Solver! *******************\n" << std::endl;
}

// Function to take input for cube colors
std::vector<std::vector<std::string>> getInput() {
    std::vector<std::vector<std::string>> cube;

    std::cout << "Valid Colors Are:  = {w=WHITE, y=YELLOW, b=BLUE, g=GREEN, r=RED, o=ORANGE} \n";
    std::cout << "Enter the colors for each side of the Rubik's Cube:\n" << std::endl; 

    // Loop through each side of the cube
    for (int side = 0; side < 6; ++side) {
        std::string sideName;
        switch (side) {
            case 0: sideName = "Front"; break;
            case 1: sideName = "Back"; break;
            case 2: sideName = "Left"; break;
            case 3: sideName = "Right"; break;
            case 4: sideName = "Top"; break;
            case 5: sideName = "Bottom"; break;
        }
        std::cout << "\n\nFor " << sideName << " Side: ------------------------ >>>\n";

        std::vector<std::string> colors;

        // Prompt for colors for each position on the side
        for (int col = 0; col < 3; ++col) {
            std::cout << "Enter color for row " << col + 1 << ": \n";
            for (int row = 0; row < 3; ++row) {
                std::string color = getValidColorInput();
                colors.push_back(color);
            }
            std::cout << "\n";
        }

        cube.push_back(colors);
    }

    return cube;
}

int main() {
    // Display welcome message
    displayWelcomeMessage();

    // Get input for cube colors
    std::vector<std::vector<std::string>> cube = getInput();

    // Display the entered cube colors
    std::cout << "\nYou entered the following cube colors:" << std::endl;
    for (int side = 0; side < 6; ++side) {
        std::string sideName;
        switch (side) {
            case 0: sideName = "Front"; break;
            case 1: sideName = "Back"; break;
            case 2: sideName = "Left"; break;
            case 3: sideName = "Right"; break;
            case 4: sideName = "Top"; break;
            case 5: sideName = "Bottom"; break;
        }
        std::cout << "For " << sideName << " Side:\n";
        for (int col = 0; col < 1; ++col) {
            for (int row = 0; row < 1; ++row) {
                std::cout << cube[side][col * 3 + row] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "\n";
    }

    // // Solve the Rubik's Cube optimally
    // CubeState initialCubeState;
    // solveOptimal(initialCubeState);

    // std::cout << "Cube solved!\n";

    return 0;
}
