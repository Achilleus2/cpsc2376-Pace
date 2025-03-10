#include <iostream>

double add(double a, double b) {
    return a + b;
}


int main() {
    std::cout << "Test 1: " << ((add(2, 3) == 5) ? "Pass" : "Fail") << ' ';
    std::cout << "Test 2: " << ((add(-1, -1) == -2) ? "Pass" : "Fail") << ' ';
    std::cout << "Test 3: " << ((add(-.1, -1) == -1.1f) ? "Pass" : "Fail") << '\n';
    return 0;
}







int divide(int a, int b) {
    if (b == 0) {
        std::cout << "Error: Division by zero\n";
        return 0;
    }
    return a / b;
}

int main() {
    std::cout << divide(10, 2) << '\n'; // Test case 1
    std::cout << divide(2,0) << '\n'; // Test case 2
    return 0;
}








bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    std::cout << std::boolalpha << isEven(4) << '\n';
    return 0;
}









void checkValue(int x) {
    if (x < 0)
        throw std::runtime_error("Negative value error");
    std::cout << "Valid number: " << x << '\n';
}

int main() {
    try {
        checkValue(5);
        checkValue(-1);
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }
    return 0;
}






int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (std::cin.fail()) {
        std::cout << "Invalid input detected\n";
    }
    else {
        std::cout << "You entered: " << num << '\n';
    }
    return 0;
}







#include <cmath>
#include <cassert>

double findHypotenuse(double a, double b) {
    double hypotenuse = std::sqrt(a * a + b * b);
    assert(hypotenuse > 0 && "Hypotenuse must be positive");
    return hypotenuse;
}

int main() {
    double x = 3.0, y = 4.0;
    std::cout << "Hypotenuse: " << findHypotenuse(x, y) << '\n';
    return 0;
}