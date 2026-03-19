#include "move.hpp"

Move::Move(int row, int col) : _row(row), _col(col) {}

int Move::get_row()
{
    return _row;
}

int Move::get_col()
{
    return _col;
}

bool Move::is_valid() const
{
    return !((this->_row > BOARD_SIZE || this->_row < 0) || (this->_col > BOARD_SIZE || this->_col < 0));
}
