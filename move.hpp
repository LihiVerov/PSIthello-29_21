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
     * @brief A boolean function that checks if the move is valid.
     * @note Valid by the board size.
     *
     * @return True if valid, otherwise, false.
     */
    bool is_valid();
};