#pragma once

#include <string>
#include "piece_type.hpp"
class Move;


/**
 * @brief Interface, represents a player in the game.
 */
class IPlayer
{
protected:
    std::string _name;
    PieceType _symbol;
public:
    /**
     * @brief Get the move player wants to do
     * @return The move player wants to do
     */
    virtual Move get_move() = 0;
};
