// rubik_solver.h

#pragma once  // This ensures that the header file is included only once

#include <vector>

// Forward declaration of CubeState and Move
class CubeState;
class Move;

// Function declarations
void solveOptimal(const CubeState& scrambledCube);
bool IDAstar(const CubeState& currentState, int depth);
void initializePatternDatabases();
CubeState applyMove(const CubeState& currentState, const Move& move);

// Define CubeState class
class CubeState {
public:
    // Add necessary member functions and data members, e.g., isSolved()
    bool isSolved() const;
};

// Define Move type
class Move {
public:
    // Add necessary member functions and data members
};

// Define possibleMoves
extern std::vector<Move> possibleMoves;

