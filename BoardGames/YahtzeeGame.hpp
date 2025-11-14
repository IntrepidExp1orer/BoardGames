#pragma once
#include <vector>
#include "Player.hpp"
#include "Game.hpp"
#include "Dice.hpp"

class YahtzeeGame : public Game {
private:
	Dice dice;
	const int HANDS = 6;
public:
	YahtzeeGame(std::vector<Player>& currentPlayers);
	void Start();
	void Process_move();
};
