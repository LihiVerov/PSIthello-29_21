#include "user.hpp"

User::User(PieceType player_type) : _player_type(player_type)
{
    if (player_type == PieceType::EMPTY)
    {
        std::cerr << "Error: Player type cannot be empty." << std::endl;
        this->_player_type = PieceType::WHITE;
    }
}

Move User::get_move() const
{
    // change type to text:
    std::string str_type, input;
    if (this->_player_type == PieceType::BLACK)
    {
        str_type = 'X';
    }
    else
    {
        str_type = 'O';
    }

    // print a message:
    std::cout << "Player " << str_type << " enter move (e.g., D3): " << std::endl;
    std::cin >> input;
    if (input.length() != 2)
    {
        User::handle_invalid_move();
    }
    while (input.length() != 2)
    {
        // show msg
        std::cout << "Invalid move!" << std::endl;
        std::cout << "Press Enter...";
        if (std::cin.get() == '\n')
        {
            std::cout << "Player " << str_type << " enter move (e.g., D3): " << std::endl;
            std::cin >> input;
        }
    }

    // convert to int:
    int row = (int)input[0] - 65; // A = 0, ...
    int col = (int)input[1];

    // create Move instance
    Move wanted_move = Move(row, col);
    return wanted_move;
}

Move User::handle_invalid_move() const
{
    std::cout << "Invalid move!" << std::endl;
    std::cout << "Press Enter...";
    if (std::cin.get() == '\n')
    {
        Move new_move = User::get_move();
        return new_move;
    }
}

Move User::get_valid_move(std::vector<Move> &valid_moves) const
{
    Move wanted_move = User::get_move();

    if (!(wanted_move.is_valid()))
    { // move is invalid by the board's size
        User::handle_invalid_move();
    }

    // handle invalid by game's rules
    bool flag = false;
    for (Move m : valid_moves)
    {
        if (m.get_col() == wanted_move.get_col() && m.get_row() == wanted_move.get_row())
        {
            flag = true;
        }
    }
    if (!flag)
    {
        User::handle_invalid_move();
    }

    return wanted_move; // the move is valid
}