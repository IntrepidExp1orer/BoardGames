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
	YahtzeeGame(const std::vector<PlayerPtr>& players);
	void Start() override;
	void Process_move();
};
