#pragma once

#include "piece_type.hpp"

/**
 * @brief Cell on the game board, can be empty or have black or white pieces
 */
class Cell
{
private:
    PieceType _piece;

public:

    /**
     * @brief Creates a new cell with a given piece
     * @param piece The piece to put on cell
     */
    Cell(PieceType piece);

    /**
     * @brief Creates a new empty cell
     */
    Cell();

    /**
     * @brief Checks if the piece is empty
     * @return true if the piece is empty or false if not
     */
    bool is_empty() const;

    /**
     * @brief Returns the piece in the cell
     * @return The piece in the cell (piece type)
     */
    PieceType get_piece() const;

    /**
     * @brief Sets the type of the piece in cell
     * @piece The type of the piece in cell
     */
    void set_piece(PieceType piece);
};
