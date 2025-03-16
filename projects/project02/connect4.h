#pragma once

#include <iostream>


class Connect4
{
private:
	std::vector<std::vector<int>> board;
	int turns = 0;
public:
	Connect4();
	void play();
	enum class gameState { onGoing, player1Wins, player2Wins, draw };
	enum Connect4::gameState status() const;
	void display() const;
	void endProgram();
	void player1Turn(std::vector<std::vector<int>>& board, int& column, int& row);
	void player2Turn(std::vector<std::vector<int>>& board, int& column, int& row);
	void ignoreLine();
	int getInt();
	std::vector<std::vector<int>> makeBoard();
	int playerTurn();
	void userMenu();
	int columnAvailibility(std::vector<std::vector<int>>& nums, int columnNum);
};
