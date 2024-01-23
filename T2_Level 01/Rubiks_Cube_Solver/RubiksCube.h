// RubiksCube.h
#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

class RubiksCube {
private:
    const static int SIZE = 3;
    char cube[6][SIZE][SIZE];

public:
    RubiksCube();  // Constructor
    void displayCube();
    void moveFrontClockwise();
    void moveFrontCounterClockwise();
    void moveRightClockwise();
    void moveRightCounterClockwise();
    // Add other necessary functions for cube manipulation
};

#endif // RUBIKSCUBE_H
