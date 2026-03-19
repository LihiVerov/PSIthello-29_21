#pragma once

#include "cell.hpp"
#include "move.hpp"
#include <vector>

#define BOARD_SIZE 8

/**
 * @brief Represents the game board and allowes to do moves on it
 */
class Board
{
private:
    Cell _cells[BOARD_SIZE][BOARD_SIZE];

    bool is_move_in_vector(std::vector<Move> valid_moves, Move move) const;

public:

    /**
     * @brief creates a new board in start position (empty cells except 4 cells with black and white)
     */
    Board();

    /**
     * @brief Prints the current board
     * @param turn The current player turn (black or white)
     */
    void print_board(PieceType turn) const;

    /**
     * @brief Returns a vector of all valid moves at this turn.
     * @param turn The current player turn (black or white)
     */
    std::vector<Move> get_valid_moves(PieceType turn) const;
};
