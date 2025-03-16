#include <iostream>
#include <vector>
#include "connect4.h"

Connect4::Connect4()
{
    Connect4::board = makeBoard();
    turns = 42;
}

void Connect4::play(int column)
{
    turns--;
    if (column > 7 || column < 1) {
        std::cerr << "\n\n\n\n\n\n*****Error: You have entered a number this isn't between 1 and 7, try again.*****";
        turns++;
    }
    else if (columnAvailibility(board, (column - 1)) > -1) {
        column -= 1;
        if (playerTurn() == 1) {
            board[columnAvailibility(board, column)][column] = 1;
        }
        else if (playerTurn() == 0) {
            board[columnAvailibility(board, column)][column] = 2;
        }
    }
    else {
        std::cerr << "\n\n\n\n\n\n*****Error: The column you have entered is full, try again.*****";
        turns++;
    }
}

std::vector<std::vector<int>> Connect4::getBoard() const
{
    return board;
}

enum Connect4::gameState Connect4::status() const
{
    for (int i = 0; i < board[0].size(); i++)
    {
        for (int j = 0; j <= (board.size() - 4); j++)
        {
            if (1 == board[j][i] && board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j + 2][i] == board[j + 3][i])
            {
                return gameState::player1Wins;
            }
        }
    }

    for (int i = 0; i < board[0].size(); i++)
    {
        for (int j = 0; j <= (board.size() - 4); j++)
        {
            if (2 == board[j][i] && board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j + 2][i] == board[j + 3][i])
            {
                return gameState::player2Wins;
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j <= (board[0].size() - 4); j++)
        {
            if (1 == board[i][j] && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3])
            {
                return gameState::player1Wins;
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j <= (board[0].size() - 4); j++)
        {
            if (2 == board[i][j] && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3])
            {
                return gameState::player2Wins;
            }
        }
    }

    if (1 == board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] == board[5][5])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][1] && board[0][1] == board[1][2] && board[1][2] == board[2][3] && board[2][3] == board[3][4])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][2] && board[1][2] == board[2][3] && board[2][3] == board[3][4] && board[3][4] == board[4][5])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][3] && board[2][3] == board[3][4] && board[3][4] == board[4][5] && board[4][5] == board[5][6])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][6] && board[0][6] == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3] && board[3][3] == board[4][2])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][4] && board[2][4] == board[3][3] && board[3][3] == board[4][2] && board[4][2] == board[5][1])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][5] && board[0][5] == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2] && board[3][2] == board[4][1])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][3] && board[2][3] == board[3][2] && board[3][2] == board[4][1] && board[4][1] == board[5][0])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][2] && board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[2][4] == board[3][5])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][3] && board[1][3] == board[2][4] && board[2][4] == board[3][5] && board[3][5] == board[4][6])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][4] && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][3] && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[0][3] && board[0][3] == board[1][4] && board[1][4] == board[2][5] && board[2][5] == board[3][6])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][6] && board[1][6] == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3] && board[4][3] == board[5][2])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[1][0] && board[1][0] == board[2][1] && board[2][1] == board[3][2] && board[3][2] == board[4][3])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][1] && board[2][1] == board[3][2] && board[3][2] == board[4][3] && board[4][3] == board[5][4])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][0] && board[2][0] == board[3][1] && board[3][1] == board[4][2] && board[4][2] == board[5][3])
    {
        return gameState::player1Wins;
    }
    else if (1 == board[2][6] && board[2][6] == board[3][5] && board[3][5] == board[4][4] && board[4][4] == board[5][3])
    {
        return gameState::player1Wins;
    }


    if (2 == board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] == board[5][5])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][1] && board[0][1] == board[1][2] && board[1][2] == board[2][3] && board[2][3] == board[3][4])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][2] && board[1][2] == board[2][3] && board[2][3] == board[3][4] && board[3][4] == board[4][5])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][3] && board[2][3] == board[3][4] && board[3][4] == board[4][5] && board[4][5] == board[5][6])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][6] && board[0][6] == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3] && board[3][3] == board[4][2])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][4] && board[2][4] == board[3][3] && board[3][3] == board[4][2] && board[4][2] == board[5][1])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][5] && board[0][5] == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2] && board[3][2] == board[4][1])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][3] && board[2][3] == board[3][2] && board[3][2] == board[4][1] && board[4][1] == board[5][0])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][2] && board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[2][4] == board[3][5])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][3] && board[1][3] == board[2][4] && board[2][4] == board[3][5] && board[3][5] == board[4][6])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][4] && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][3] && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[0][3] && board[0][3] == board[1][4] && board[1][4] == board[2][5] && board[2][5] == board[3][6])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][6] && board[1][6] == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][5] && board[2][5] == board[3][4] && board[3][4] == board[4][3] && board[4][3] == board[5][2])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[1][0] && board[1][0] == board[2][1] && board[2][1] == board[3][2] && board[3][2] == board[4][3])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][1] && board[2][1] == board[3][2] && board[3][2] == board[4][3] && board[4][3] == board[5][4])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][0] && board[2][0] == board[3][1] && board[3][1] == board[4][2] && board[4][2] == board[5][3])
    {
        return gameState::player2Wins;
    }
    else if (2 == board[2][6] && board[2][6] == board[3][5] && board[3][5] == board[4][4] && board[4][4] == board[5][3])
    {
        return gameState::player2Wins;
    }

    if (turns == 0)
    {
        return gameState::draw;
    }
    else
    {
        return gameState::onGoing;
    }
}

std::ostream& operator<<(std::ostream& out, const Connect4& a)
{
    out << "\n\n\n\n\n\n\n";
    out << "*Rules*\nSetup : Player #1 gets an X board piece and player #2 gets a O board piece. Take turns dropping one piece into a column.\n"
        << "Objective : Be the first to connect four of your pieces in a row, column, or diagonal.\n"
        << "Turns : Players take turns dropping one piece at a time. Pieces stack on top of each other.\n"
        << "Winning : If a player connects four in a row, they win!\n";
    out << "-----------------\n";
    for (int i = 0; i < a.board.size(); i++)
    {
        out << "| ";
        for (int j = 0; j < a.board[0].size(); j++)
        {
            if (a.board[i][j] == 0) out << ". ";
            else if (a.board[i][j] == 1) out << "X ";
            else if (a.board[i][j] == 2) out << "O ";
        }
        out << "|\n";
    }
    out << "-----------------\n";
    out << "  1 2 3 4 5 6 7\n";
    out << "Turns left: " << a.turns << "\n";
    return out;
}

void Connect4::display() const
{
    std::cout << *this;
}

std::vector<std::vector<int>> Connect4::makeBoard()
{
    std::vector<std::vector<int>> nums = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0} };
    return nums;
}

int Connect4::playerTurn()
{
    return turns % 2;
}

int Connect4::columnAvailibility(std::vector<std::vector<int>>& nums, int columnNum)
{
    for (int i = 5; i >= 0; i--)
    {
        if (nums[i][columnNum] == 0)
        {
            return i;
        }
    }
    return -1;
}

