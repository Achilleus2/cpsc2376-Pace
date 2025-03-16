#include <iostream>
#include <vector>
#include "connect4.h"

void ignoreLine();
int getInt();


int main() {
    while (true)
    {
        Connect4 a;
        a.userMenu();
        a.display();
        while (a.status() == Connect4::gameState::onGoing)
        {
            int player = 1;
            if ((a.playerTurn() - 1) == 0) {
                player = 2;
            }
            int column;
            int row;
            std::vector<std::vector<int>> b = a.getBoard();
            while (true) {
                std::cout << "Player " << player << " enter the number of the column you would like to send your piece down into : ";
                int playerChoice = getInt();
                if (playerChoice > 7 || playerChoice < 1) {
                    std::cerr << "*Error: You have entered a number this isn't between 1 and 7, try again.*\n\n";
                }
                else if (a.columnAvailibility(b, (playerChoice - 1)) > -1) {
                    column = playerChoice - 1;
                    row = a.columnAvailibility(b, (playerChoice - 1));
                    break;
                }
                else {
                    std::cerr << "*Error: The column you have entered is full, try again.*\n\n";
                }
            }
            a.play(row, column);
            a.display();
        }
        if (a.status() == Connect4::gameState::player1Wins) {
            std::cout << "Player 1 wins" << std::endl;
        }
        else if (a.status() == Connect4::gameState::player2Wins) {
            std::cout << "Player 2 wins" << std::endl;
        }
        else {
            std::cout << "Game has ended in a Draw" << std::endl;
        }
        std::cout << "Enter 1 to play or any other integer value to exit the program: ";
        int choice = getInt();
        if (choice != 1)
        {
            return 0;
        }
    }
   
    return 0;
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt()
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