/*#include <iostream>
int main() {
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
int main() {
    std::vector<int> numbers = { 10, 20, 30, 40, 50 };
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << numbers[5];
    return 0;
}*/

/*#include <iostream>
#include <vector>

void printByCopy(std::vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        numbers.at(i) *= 2;
        std::cout << numbers.at(i) << " ";
    }
}

void printByReference(std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        numbers.at(i) *= 2;
        std::cout << numbers.at(i) << " ";
    }
}

void printByConstReference(const std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i) << " ";
    }
}

int main() {
    std::vector<int> myNumbers = { 1, 2, 3, 4, 5 };

    printByCopy(myNumbers);
    std::cout << std::endl;

    printByReference(myNumbers);
    std::cout << std::endl;

    printByConstReference(myNumbers);
    std::cout << std::endl;

    return 0;
}*/

/*#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Adding elements
    numbers.push_back(10);
    numbers.push_back(20);
    std::cout << "Vector size after adding elements: " << numbers.size() << std::endl;

    // Reserving space
    numbers.reserve(10);
    std::cout << "Vector capacity after reserve: " << numbers.capacity() << std::endl;

    // Resizing the vector
    numbers.resize(10);
    std::cout << "Vector size after resize: " << numbers.size() << std::endl;

    return 0;
}
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    for (int i = 1; i <= 5; i++) {
        numbers.push_back(i * 10); // Add 10, 20, 30, 40, 50
    }

    std::cout << "Even numbers: ";
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers.at(i) % 2 == 0) {
            std::cout << numbers.at(i) << " ";
        }
    }

    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers.at(i) % 2 == 1) {
            sum += numbers.at(i);
        }
    }

    std::cout << "\nSum of all numbers: " << sum << std::endl;

    return 0;
}
