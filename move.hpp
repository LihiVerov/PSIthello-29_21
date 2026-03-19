#pragma once
#define BOARD_SIZE 8

/**
 * @brief A class that represents a move for a player.
 */
class Move
{
private:
    int _row;
    int _col;

public:
    /**
     * @brief A full constructor.
     *
     * @param row The value for row.
     * @param col The value for col.
     */
    Move(int row, int col);

    /**
     * @brief Get the move row
     * @return row of the move
     */
    int get_row() const;

    /**
     * @brief Get the move col
     * @return col of the move
     */
    int get_col() const;

    /**
     * @brief A boolean function that checks if the move is valid.
     * @note Valid by the board size.
     *
     * @return True if valid, otherwise, false.
     */
    bool is_valid() const;
};
