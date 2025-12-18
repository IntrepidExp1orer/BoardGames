#pragma once
#include <vector>
#include "Player.hpp"
#include "Game.hpp"
#include "Dice.hpp"

class YahtzeeGame : public Game {
private:
	Dice dice;
	static int hands;
public:
	YahtzeeGame(const std::vector<PlayerPtr>& players, std::string name);
	~YahtzeeGame() override = default;
	void Start() override;
	void Process_move();
	void Rules() const override;
	void GameInfo(int handCount);

	static void SetHands(int number);
	static int GetHands();

	YahtzeeGame& operator=(const Game& other);
};
