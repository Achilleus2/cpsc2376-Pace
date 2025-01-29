#include <iostream>
#include <vector>

void printVector(const std::vector<int>& nums);       //Initializing functions that will be used in main
void doubleVector(std::vector<int>& nums);
void calculateSum(const std::vector<int>& nums);
void printMultiples(const std::vector<int>& nums, int mult);

int main(){
	int choice = 0;
	std::vector<int> numbers{}; 

	while (choice < 6 && choice >= 0){           //While loop that runs the user menu until user opts out by entering an int value outside of 0 and 5
		if (choice == 1) {
			int newVal{ 0 };
			std::cout << "Enter a whole number value: " << std::endl;
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
			std::cout << "\n" << std::endl;
			printMultiples(numbers, multiple);
		}
		
		std::cout << "\n\n1. Add an item to a vector \n"            // User menu
				  << "2. Print the vector \n"
				  << "3. Double the vector \n"
				  << "4. Find the sum \n"
				  << "5. Print multiples of a user-defined value \n"
				  << "6. Exit \n"
				  << "*Enter the number at the beginning of which action you would like to choose* \n"
				  << "    *Any value outside of the numbers 0 through 6 will end the program*" << std::endl;
		std::cin >> choice;
		std::cout << " \n" << std::endl;
	}
	return 0;
}

void printVector(const std::vector<int>& nums){ //Function for printing a vector with int values
	std::cout << "Vector: ";
	for (int i = 0; i < nums.size(); i++){
		std::cout << nums.at(i) << " ";
	}
	std::cout << "" << std::endl;
}

void doubleVector(std::vector<int>& nums){      //Function for permenantly doubling a vector with int values
	for (int i = 0; i < nums.size(); i++){
		nums[i] *= 2;
	}
}

void calculateSum(const std::vector<int>& nums){ //Function for calculation the sum of all the element in a vector with int values
	int sum{};
	for (int i = 0; i < nums.size(); i++){
		sum += nums.at(i);
	}
	std::cout << "Sum: " << sum << std::endl;
}

void printMultiples(const std::vector<int>& nums, int mult){  //Function for printing the elements in a vector that are multiples of users input int value
	std::cout << "Multiples of " << mult << ": ";
	for (int i = 0; i < nums.size(); i++){
		if (((nums.at(i))%mult) == 0){
			std::cout << nums.at(i) << " ";
		}
	}
	std::cout <<"" << std::endl;
}