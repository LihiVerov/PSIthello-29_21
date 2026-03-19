#pragma once

#include <string>
#include "piece_type.hpp"
class Move;

class IPlayer
{
protected:
    std::string _name;
    PieceType _symbol;
public:
    virtual Move get_move() = 0;
};
