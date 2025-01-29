#include <iostream>
#include <vector>

int main(){
	int choice = 0;
	std::vector<double> numbers{};
	while (choice < 6 && choice >= 0){
		if (choice == 1) {
			double newVal{ 0 };
			std::cout << "Enter a numerical value: " << std::endl;
			std::cin >> newVal;
			numbers.push_back(newVal);
		}
		else if (choice == 2) {
			printVector(numbers);
		}
		else if (choice == 3) {
			doubleVector(numbers);
		}
		else if (choice == 4) {
			calculateSum(numbers);
		}
		else if (choice == 5) {
			int multiple{ 1 };
			std::cout << "Enter the multiple you would like to check for: " << std::endl;
			std::cin >> multiple;
			printMultiples(numbers, multiple);
		}
		std::cout << "1. Add an item to a vector /n2.Print the vector /n3.Double the vector /n4.Find the sum /n5.Print multiples of a user-defined value /n6.Exit /n*Enter the number at the beginning of which action you would like to choose*" << std::endl;
		std::cin >> choice;
		std::cout << " /n/n" << std::endl;


		return 0;
	}
}

void printVector(const std::vector<double>& nums){
	for (int i = 0; i < nums.size(); i++){
		std::cout << nums.at(i) << std::endl;
	}
}

void doubleVector(std::vector<int>& nums){
	for (int i = 0; i < nums.size(); i++){
		nums[i] *= 2;
	}
}

void calculateSum(const std::vector<double>& nums){
	double sum{};
	for (int i = 0; i < nums.size(); i++){
		sum += nums.at(i);
	}
	std::cout << "Sum: " << sum << std::endl;
}

void printMultiples(const std::vector<double>& nums, int mult){
	for (int i = 0; i < nums.size(); i++){
		if ((nums.at(i) % mult) == 0){
			std::cout << nums.at(i) << std::endl;
		}
	}
}