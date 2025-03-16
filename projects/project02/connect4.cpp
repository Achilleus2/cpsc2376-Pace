#include <iostream>
#include <vector>
#include <cstdlib>
#include "connect4.h"

Connect4::Connect4()
{
    Connect4::board = makeBoard();
    turns = 42;
}

void Connect4::play()
{
    turns--;
    if (playerTurn() == 1) {
        int column;
        int row;
        player1Turn(board, column, row);
        board[row][column] = 1;
    }
    else if (playerTurn() == 0) {
        int column;
        int row;
        player2Turn(board, column, row);
        board[row][column] = 2;
    }
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

void Connect4::display() const
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "-----------------\n";
    for (int i = 0; i < board.size(); i++)
    {
        std::cout << "| ";
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0) std::cout << ". ";
            else if (board[i][j] == 1) std::cout << "X ";
            else if (board[i][j] == 2) std::cout << "O ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-----------------\n";
    std::cout << "  1 2 3 4 5 6 7\n";
    std::cout << "Turns left: " << turns << std::endl;
}

void Connect4::endProgram()
{
    std::cout << "Exiting program...\n";
    exit(0);
}

void Connect4::player1Turn(std::vector<std::vector<int>>& board, int& column, int& row)
{
    while (true) {
        std::cout << "Player 1 enter the number of the column you would like to send your piece down into: ";
        int player1Choice = getInt();
        if (player1Choice > 7 || player1Choice < 1) {
            std::cerr << "Error: You have entered a number this isn't between 1 and 7, try again.\n\n";
        }
        else if (columnAvailibility(board, (player1Choice - 1)) > -1) {
            column = player1Choice - 1;
            row = columnAvailibility(board, (player1Choice - 1));
            break;
        }
        else {
            std::cerr << "Error: The column you have entered is full, try again.\n\n";
        }
    }
}

void Connect4::player2Turn(std::vector<std::vector<int>>& board, int& column, int& row)
{
    while (true) {
        std::cout << "Player 2 enter the number of the column you would like to send your piece down into: ";
        int player2Choice = getInt();
        if (player2Choice > 7 || player2Choice < 1) {
            std::cerr << "Error: You have entered a number this isn't between 1 and 7, try again.\n\n";
        }
        else if (columnAvailibility(board, (player2Choice - 1)) > -1) {
            column = player2Choice - 1;
            row = columnAvailibility(board, (player2Choice - 1));
            break;
        }
        else {
            std::cerr << "Error: The column you have entered is full, try again.\n\n";
        }

    }
}

void Connect4::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Connect4::getInt()
{
    while (true)
    {
        int x{};
        std::cin >> x;
        bool success{ std::cin };
        std::cin.clear();
        ignoreLine();
        if (success)
            return x;
        else
            std::cerr << "*Error invalid input* \n Try again: ";
    }
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

void Connect4::userMenu()
{
    std::cout << "*Rules*\nSetup : Player #1 gets an X board piece and player #2 gets a O board piece. Take turns dropping one piece into a column.\n"
        << "Objective : Be the first to connect four of your pieces in a row, column, or diagonal.\n"
        << "Turns : Players take turns dropping one piece at a time. Pieces stack on top of each other.\n"
        << "Winning : If a player connects four in a row, they win!\n\n"
        << "Enter the number 1 to continue or 0 to exit the program: ";
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
