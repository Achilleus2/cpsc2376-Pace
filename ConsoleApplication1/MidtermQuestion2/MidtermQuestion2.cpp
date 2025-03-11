#include <iostream>
#include <fstream>
#include <string>
#include <vector>




void Read(const std::string & filename, std::vector<int>& p) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading." << std::endl;
        return;
    }
    int line;
    while (inFile >> line) {
        p.push_back(line);
    }
    inFile.close();
}

template <typename T, typename U>
auto max(T a, U b)
{
    if (a > b)
        return a;
    else
        return b;
}

void findLargest(const std::vector<int>& nums, int& maxVal)
{
    if (nums.empty()) {
        std::cerr << "The vector is empty. Can't find the largest value." << std::endl;
        return;
    }
    maxVal = nums.at(0);
    std::vector<int>::const_iterator it;
    for (it = nums.begin(); it != nums.end(); ++it)
    {
        maxVal = max(*it, maxVal);
    }
}


//example.txt

int main()
{
    std::vector<int> content;
    std::cout << "Enter the name of a file: ";
    std::string filename;
    std::cin >> filename;

    std::cout << "Integers: ";
    Read(filename, content);
    for (int i = 0; i < content.size(); i++)
    {
        std::cout << content.at(i) << " ";
    }
    std::cout << "\n";
    
    int maxValue;
    findLargest(content, maxValue);
    std::cout << "Largest value: " << maxValue;

}