#include "board.hpp"
#include <iostream>

bool Board::is_move_in_vector(const std::vector<Move>& valid_moves, Move move) const
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

bool Board::is_move_valid_at_direction(const Move& move, PieceType turn, Direction direction) const
{
    int add_to_row = 0;
    int add_to_col = 0;

    switch (direction)
    {
    case Direction::UP:
        add_to_row = -1;
        break;
    case Direction::UP_LEFT:
        add_to_row = -1;
        add_to_col = -1;
        break;
    case Direction::UP_RIGHT:
        add_to_row = -1;
        add_to_col = 1;
        break;
    case Direction::RIGHT:
        add_to_col = 1;
        break;
    case Direction::LEFT:
        add_to_col = -1;
        break;
    case Direction::DOWN:
        add_to_row = 1;
        break;
    case Direction::DOWN_LEFT:
        add_to_row = 1;
        add_to_col = -1;
        break;
    case Direction::DOWN_RIGHT:
        add_to_row = 1;
        add_to_col = 1;
        break;
    }
    
    if (add_to_row == 1 && move.get_row() == BOARD_SIZE - 1)
    {
        return false;
    }
    if (add_to_row == -1 && move.get_row() == 0)
    {
        return false;
    }
    if (add_to_col == 1 && move.get_col() == BOARD_SIZE - 1)
    {
        return false;
    }
    if (add_to_col == -1 && move.get_col() == 0)
    {
        return false;
    }
    
    
    if (_cells[move.get_row() + add_to_row][move.get_col() + add_to_col].is_empty() || _cells[move.get_row() + add_to_row][move.get_col() + add_to_col].get_piece() == turn)
    {
        return false;
    }
    
    int row = move.get_row() + add_to_row;
    int col = move.get_col() + add_to_col;

    while (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE)
    {
        if (_cells[row][col].is_empty() && (row != move.get_row() || col != move.get_col()))
        {
            return false;
        }
        if (_cells[row][col].get_piece() == turn)
        {
            return true;
        }

        row += add_to_row;
        col += add_to_col;
    }
    return false;
}

bool Board::is_move_valid(const Move& move, PieceType turn) const
{
    bool result = false;
    result = result || is_move_valid_at_direction(move, turn, Direction::UP);
    result = result || is_move_valid_at_direction(move, turn, Direction::UP_RIGHT);
    result = result || is_move_valid_at_direction(move, turn, Direction::UP_LEFT);
    result = result || is_move_valid_at_direction(move, turn, Direction::LEFT);
    result = result || is_move_valid_at_direction(move, turn, Direction::RIGHT);
    result = result || is_move_valid_at_direction(move, turn, Direction::DOWN);
    result = result || is_move_valid_at_direction(move, turn, Direction::DOWN_RIGHT);
    result = result || is_move_valid_at_direction(move, turn, Direction::DOWN_LEFT);
    return result;
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
            else if (_cells[i][j].get_piece() == PieceType::WHITE)
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

std::vector<Move> Board::get_valid_moves(PieceType turn) const
{
    std::vector<Move> valid_moves;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (_cells[i][j].is_empty())
            {
                Move curr_move = Move(i, j);
                if (is_move_valid(curr_move, turn))
                {
                    valid_moves.push_back(curr_move);
                }
            }
        }
    }
    return valid_moves;
}

void Board::place_piece(const Move& move, PieceType turn)
{
    if (!is_move_valid(move, turn))
    {
        return; // do nothing, other functions supposed to make share it won't happen
    }
    int add_to_row = 0;
    int add_to_col = 0;
    if (is_move_valid_at_direction(move, turn, Direction::UP))
    {
        add_to_row = -1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::UP_RIGHT))
    {
        add_to_row = -1;
        add_to_col = 1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::UP_LEFT))
    {
        add_to_row = -1;
        add_to_col = -1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::LEFT))
    {
        add_to_col = -1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::RIGHT))
    {
        add_to_col = 1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::DOWN))
    {
        add_to_row = 1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::DOWN_RIGHT))
    {
        add_to_row = 1;
        add_to_col = 1;
    }
    else if (is_move_valid_at_direction(move, turn, Direction::DOWN_LEFT))
    {
        add_to_row = 1;
        add_to_col = -1;
    }

    int row = move.get_row();
    int col = move.get_col();
    PieceType not_turn = PieceType::BLACK;
    if (turn == PieceType::BLACK)
    {
        not_turn = PieceType::WHITE;
    }

    _cells[row][col].set_piece(not_turn);
    while (_cells[row][col].get_piece() != turn)
    {
        if (_cells[row][col].get_piece() == not_turn)
        {
            _cells[row][col].set_piece(turn);
        }

        row += add_to_row;
        col += add_to_col;
    }
}

int main()
{
    Board board = Board();

    board.print_board(PieceType::BLACK);
    board.place_piece(Move(2, 3), PieceType::BLACK);
    board.print_board(PieceType::BLACK);

    return 0;
}