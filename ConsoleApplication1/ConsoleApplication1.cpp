/*#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    std::vector<int>::iterator it = numbers.begin();
    std::cout << "First element: " << *it << std::endl;
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> numbers = { 10, 20, 30, 40, 50 };
    auto it = numbers.begin();
    auto nextIt = std::next(it, 2);
    std::cout << "Value at nextIt: " << *nextIt << std::endl;
    return 0;
}*/

/*#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> values = { 1, 2, 3, 4, 5 };
    int sum = std::accumulate(values.begin(), values.end(), 0);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values = { 5, 2, 8, 3, 1 };
    std::sort(values.begin(), values.end(), [](int a, int b) { return a % 2 < b % 2; });
    for (int v : values) {
        std::cout << v << " ";
    }
    return 0;
}*/