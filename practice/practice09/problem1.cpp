#include <iostream>
#include <string>

int main() {
    float redPotion{ 0.0f }; 
    float bluePotion{ 0.0f }; 
    float* flask{ nullptr }; 
    std::string input;

    while (true) {
        std::cout << "\nWhich potion to add liquid to? (Red, Blue, or Done): ";
        std::getline(std::cin, input);

        if (input == "Done" || input == "done") {
            std::cout << "Brewing session ended.\n";
            break;
        }

        if (input == "Red" || input == "red") {
            flask = &redPotion;
        }
        else if (input == "Blue" || input == "blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Invalid potion name. Please enter Red, Blue, or Done.\n";
            continue;
        }

        float amountToAdd{ 0.0f };
        std::cout << "How many milliliters to add?: ";
        std::cin >> amountToAdd;
        std::cin.ignore();

        *flask += amountToAdd;

        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n";
    }

    return 0;
}