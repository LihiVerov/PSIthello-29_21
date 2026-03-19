#pragma once

#include "cell.hpp"
#include "move.hpp"
#include "direction.hpp"
#include <vector>

#define BOARD_SIZE 8

/**
 * @brief Represents the game board and allowes to do moves on it
 */
class Board
{
private:
    Cell _cells[BOARD_SIZE][BOARD_SIZE];

    /**
     * @brief Checks if a certain move is in valid moves vector
     * @param valid_moves valid moves vector
     * @param move Move to check if in vector
     * @return true if move is in vector and false if not
     */
    bool is_move_in_vector(const std::vector<Move>& valid_moves, Move move) const;

    /**
     * @brief Checks if move is valid on a certain direction
     * @param move the move to check if valid
     * @param turn the turn to check if move is valid in
     * @param direction the direction to check move in
     * @return true if move can be done on this direction or false if not
     */
    bool is_move_valid_at_direction(const Move& move, PieceType turn, Direction direction) const;

    /**
     * @brief Checks if move is valid
     * @param move the move to check if valid
     * @param turn the turn to check if move is valid in
     * @return true if move is valid
     */
    bool is_move_valid(const Move& move, PieceType turn) const;

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

    /**
     * @brief Place a piece on board and flip the relevant pieces
     * @param move The move to place piece on board with
     * @param turn The turn of the current player (black or white)
     */
    void place_piece(const Move& move, PieceType turn);
};
