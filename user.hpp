#pragma once
#include "iplayer.hpp"
#include "move.hpp"
#include <string>
#include <iostream>
#include <vector>

/**
 * @brief A class that allows a user to play their turn in the game.
 * @note This class inherits from IPlayer interface.
 */
class User : public IPlayer
{
private:
    PieceType _player_type;

public:
    /**
     * @brief An explicit constructor.
     *
     * @param player_type The type of the user player.
     */
    explicit User(PieceType player_type);

    /**
     * @brief An overridden function that gets input from the user and creates a move out of it.
     *
     * @return The move the user inputed.
     */
    Move get_move() const override;

    /**
     * @brief A function that checks if a move is valid. If so, it'll return the move. Otherwise, it'll call
     * get_move() until getting a valid move.
     * 
     * @param valid_moves A vector of Moves that contains all the current valid moves
     * that the user might choose to take.
     *
     * @return A valid move.
     */
    Move get_valid_move(std::vector<Move>& valid_moves) const;


    /**
     * @brief A function that handles the input of invalid move.
     * The function calles get_move() to get a different input.
     * @note It's called when getting invalid lengthed input, and when checking if the move is valid.
     * 
     * @return The new move.
     */
    Move handle_invalid_move() const;

};
