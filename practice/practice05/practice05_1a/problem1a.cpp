#include <iostream>
#include <vector>
#include <numeric>

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

int main()
{
    std::vector<int> values{};
    int userChoice{ -1 };

    std::cout << "Enter a list of interger values \n";
    while (userChoice != 0)
    {
        std::cout << "\n\nEnter: ";
        values.push_back(getInt());
        userChoice = -1;
        while (userChoice > 1 || userChoice < 0)
        {
            std::cout << "Enter 1 to add another number or 0 to end your list of integers: ";
            userChoice = getInt();
            if (userChoice > 1 || userChoice < 0)
            {
                std::cerr << "*Error interger is not 1 or 0,try again. ";
            }
        }
    }

    int sum = {};
    std::cout << "\n\n\nIntegers: ";
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << " ";
        if (*it % 2 == 0)
        {
            sum += *it;
        }
    }
    std::cout << "\nSum of even integers: " << sum << std::endl;

    return 0;
}
