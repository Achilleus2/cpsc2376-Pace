#include <iostream>

double convertTemperature(double temp, char scale = 'F');

int main()
{
	std::cout << convertTemperature(50, 'C');
	
	return 0;
}

double convertTemperature(double temp, char scale)
{
	if (scale == 'C')
	{
		std::cout << "C:";
		return ((temp - 32) / 1.8);
	}
	else if (scale == 'F')
	{
		std::cout << "F:";
		return (temp * 1.8 + 32);
	}
}
