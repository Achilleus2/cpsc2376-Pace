#pragma once

#include <iostream>


class Connect4
{
private:
	std::vector<std::vector<int>> board;
	int turns = 0;
public:
	Connect4();
	void play(int column);
	enum gameState { onGoing, player1Wins, player2Wins, draw };
	enum Connect4::gameState status() const;
	void display() const;
	int playerTurn() const;
	friend std::ostream& operator<<(std::ostream& out, const Connect4& game);
};