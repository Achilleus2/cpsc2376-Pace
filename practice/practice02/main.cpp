#include <iostream>
#include <fstream>
#include <string>

void checkBalance(const std::string& accountFile);
void deposit(const std::string& accountFile, double depositAmount);
void withdraw(const std::string& accountFile, double withdrawAmount);
double readBalanceFromFile(const std::string& accountFile);
void writeBalanceToFile(const std::string& accountFile, const std::string& balance);

int main()
{
	std::cout << "Welcome to Your Bank Account!" << std::endl;
	std::ifstream accountT("account_balance.txt");
		if (accountT.good())
		{
			accountT.close();
			std::cout << "Your current balance is: ";
			checkBalance("account_balance.txt");
			std::cout << "\n" << std::endl;
		}
		else
		{
			std::ofstream account("account_balance.txt");
			writeBalanceToFile("account_balance.txt", 100.00);
			std::cout << "Initializing account with $100.00...\n" << std::endl;
		}
		double menuChoice = 0;
		while (menuChoice != 4)
		{
			if (menuChoice == 1)
			{
				std::cout << "Your current balance is: ";
				checkBalance("account_balance.txt");
				std::cout << " " << std::endl;
			}
			else if (menuChoice == 2)
			{
				double depositA = 0;
				std::cout << "Enter deposit amount: ";
				std::cin >> depositA;
				std::cout << "" << std::endl;
				deposit("account_balance.txt", depositA);
			}
			else if (menuChoice == 3)
			{
				double withdrawA = 0;
				std::cout << "Enter withdraw amount: ";
				std::cin >> withdrawA;
				std::cout << "" << std::endl;
				withdraw("account_balance.txt", withdrawA);
			}
			else if (menuChoice < 0 or menuChoice > 4)
			{
				std::cout << "Error: Choice entered is not supported." << std::endl;
			}

			std::cout << "Menu:"
				<< "1. Check Balance"
				<< "2. Deposit Money"
				<< "3. Withdraw Money"
				<< "4. Exit\n"
				<< "Enter your choice: ";
			std::cin >> menuChoice;
		}


	return 0;
}


void checkBalance(const std::string& accountFile)
{
	std::cout << "$"; 
	readBalanceFromFile(accountFile);
}

void deposit(const std::string& accountFile, double depositAmount)
{
	double newBalance;
	if (depositAmount < 0)
	{
		std::cout << "Error: Deposit amount must be positive." << std::endl;
		return;
	}
	else
	{
		newBalance = readBalanceFromFile(accountFile) + depositAmount;
		writeBalanceToFile(accountFile, newBalance);
		std::cout << "Deposit successful. Your new balance is: ";
		checkBalance(accountFile);
		std::cout << "" << std::endl;
		return;
	}
}

void withdraw(const std::string& accountFile, double withdrawAmount)
{
	if (withdrawAmount < 0)
	{
		std::cout << "Error: Withdraw amount must be positive." << std::endl;
		return;
	}
	else
	{
		if (withdrawAmount > readBalanceFromFile(accountFile))
		{
			std::cout << "Error: Insufficent funds. Your balance is: "; 
			checkBalance(accountFile);
			std::cout << "" << std::endl;
			return;
		}
		else
		{
			double newBalance = readBalanceFromFile(accountFile) - withdrawAmount;
			writeBalanceToFile(accountFile, newBalance);
			std::cout << "Withdraw successful. Your new balance is: ";
			checkBalance(accountFile);
			std::cout << "" << std::endl;
		}
	}
}

double readBalanceFromFile(const std::string& accountFile)
{
	std::ifstream inFile(accountFile);
	double amount;
	if (!inFile.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}
	else
	{
		inFile >> amount;
		if (!inFile)
		{
			std::cerr << "Failed to read from file" << std::endl;
			return;
		}
		inFile.close();
		return amount;
	}
}

void writeBalanceToFile(const std::string& accountFile, double balance)
{
	std::ofstream outFile(accountFile, std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}
	else
	{
		outFile << balance;
		outFile.close();
	}
}
