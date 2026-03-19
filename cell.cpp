#include "cell.hpp"

Cell::Cell(PieceType piece)
{
    _piece = piece;
}

Cell::Cell()
{
    _piece = PieceType::EMPTY;
}

bool Cell::is_empty() const
{
    return _piece == PieceType::EMPTY;
}

PieceType Cell::get_piece() const
{
    return _piece;
}

void Cell::set_piece(PieceType piece)
{
    _piece = piece;
}

