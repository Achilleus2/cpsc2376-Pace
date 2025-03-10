#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename, const std::string& content) {
    //std::ofstream outFile(filename);
    std::ofstream outFile(filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
    }
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

void simpleRead(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading." << std::endl;
        return;
    }
    std::string line;
    while (inFile >> line) {
        std::cout << line << std::endl;
    }
}

int main() {
    writeToFile("input.txt", "Peanut Butter Sandwhiches are very tasty");
    simpleRead("input.txt");
    return 0;
}

/*
int main() {
    writeToFile("example.txt", "Hello, world!\nThis is a file example.");
    return 0;
}*/
/*
int main() {
    writeToFile("example.txt", "First write.\n");
    writeToFile("example.txt", "Second write.\n");
    return 0;
}*/

void readWriteConflict(const std::string& filename) {
    std::ofstream outFile(filename);
    std::ifstream inFile(filename);

    if (outFile.is_open() && inFile.is_open()) {
        outFile << "Writing to file." << std::endl;
        std::string line;
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cerr << "Failed to open file." << std::endl;
    }
}

int main() {
    readWriteConflict("example.txt");
    return 0;
}