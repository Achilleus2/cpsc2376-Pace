#include <iostream>
#include <vector>
#include <cstdlib>
#include "connect4.h"

void endProgram();
void ignoreLine();
int getInt();


int main() {
    Connect4 a;
    a.userMenu();
    a.display();
    while (a.status() == Connect4::gameState::onGoing)
    {
        a.play();
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

    return 0;
}

void endProgram()
{
    std::cout << "Exiting program...\n";
    exit(0);
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