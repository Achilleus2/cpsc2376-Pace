#include <iostream>
#include <random>
#include <vector>

struct minMax {int max;int min;};
int sum(std::vector<int> nums);
void minAndMax(minMax& p, const std::vector<int>& nums);
double average(const std::vector<int>& nums);

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);

	std::cout << "How many random numbers would you like to generate? " << std::endl;
	int randNums;
	std::cin >> randNums;
	std::vector<int> nums;
	
	std::cout << "Numbers: ";
	for (int i = 0; i < randNums; i++)
	{
		nums.push_back(distr(gen));
	}

	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums.at(i) << " ";
	}

	std::cout << "\nSum of numbers: " << sum(nums) << std::endl;

	minMax p{ 0,0 };
    minAndMax(p,nums);
	std::cout << "Max: " << p.max << "  Min:" << p.min;

	std::cout << "\nAverage: " << average(nums);

	return 0;
}


int sum(std::vector<int> nums)
{
	int sum{ 0 };
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums.at(i);
	}
	return sum;
}

void minAndMax(minMax& p, const std::vector<int>& nums)
{
	int max = nums.at(0);
	int min = nums.at(0);
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums.at(i) > max)
		{
			max = nums.at(i);
		}
		if (nums.at(i) < min)
		{
			min = nums.at(i);
		}
	}
	p.max = max;
	p.min = min;
}

double average(const std::vector<int>& nums)
{
	int total = sum(nums);
	double numberOfNums = nums.size();

	return total/numberOfNums;
}
