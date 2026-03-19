#include "board.hpp"
#include <iostream>

bool Board::is_move_in_vector(std::vector<Move> valid_moves, Move move) const
{
    for (auto& curr_move : valid_moves)
    {
        if (move.get_row() == curr_move.get_row() && move.get_col() == curr_move.get_col())
        {
            return true;
        }
    }
    return false;
}

Board::Board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((i == 3 && j == 3) || (i == 4 && j == 4))
            {
                _cells[i][j] = PieceType::WHITE;
            }
            else if ((i == 3 && j == 4) || (i == 4 && j == 3))
            {
                _cells[i][j] = PieceType::BLACK;
            }
            else
            {
                _cells[i][j] = PieceType::EMPTY;
            }
        }
    }
}

void Board::print_board(PieceType turn) const
{
    if (turn == PieceType::EMPTY)
    {
        return;
    }

    std::cout << "  ";
    for (char ch = 'A'; ch <= 'H'; ch++)
    {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    std::vector<Move> valid_moves = get_valid_moves(turn);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (is_move_in_vector(valid_moves, Move(i, j)))
            {
                std::cout << "* ";
            }
            if (_cells[i][j].get_piece() == PieceType::WHITE)
            {
                std::cout << "O ";
            }
            else if (_cells[i][j].get_piece() == PieceType::BLACK)
            {
                std::cout << "X ";
            }
            else
            {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

