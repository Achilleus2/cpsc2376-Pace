#include <iostream>
#include <vector>
#include <numeric>


int main()
{
    std::vector<int> values{20, 90, 2, 3, 5}; 

    int sum = std::accumulate(values.begin(), values.end(), 0);
    int product{1};
    for (auto it = values.begin(); it != values.end(); ++it) { 
        product *= *it;
    }
    std::cout << "\nSum of even integers: " << sum << std::endl;
    std::cout << "\nProduct of even integers: " << product << std::endl;


    return 0;
}

