#include <iostream>
#include <vector>
#include "connect4.h"

void ignoreLine();
int getInt();


int main() {
    while (true)
    {
        Connect4 a;
        a.display();
        while (a.status() == Connect4::gameState::onGoing)
        {            
            std::cout << "Player " << a.playerTurn() << " enter the number of the column you would like to send your piece down into : ";
            int column = getInt();
            a.play(column);
            a.display();
        }
        if (a.status() == Connect4::gameState::player1Wins) {
            std::cout << "Player 1 wins" << std::endl;
        }
        else if (a.status() == Connect4::gameState::player2Wins) {
            std::cout << "Player 2 wins" << std::endl;
        }
        else if (a.status() == Connect4::gameState::draw) {
            std::cout << "Game has ended in a Draw" << std::endl;
        }
        std::cout << "Enter 1 to play again or any other integer value to exit the program: ";
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
            std::cerr << "\n*****Error invalid input***** \n\n Try again: ";
    }
}