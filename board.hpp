#pragma once

#include "cell.hpp"

#define BOARD_SIZE 8

/**
 * @brief Represents the game board and allowes to do moves on it
 */
class Board
{
private:
    Cell _cells[BOARD_SIZE][BOARD_SIZE];

public:

    /**
     * @brief creates a new board in start position (empty cells except 4 cells with black and white)
     */
    Board();

    /**
     * @brief Prints the current board
     */
    void print_board() const;
};
