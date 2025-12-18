#pragma once
#include <vector>
#include "Player.hpp"
#include "Game.hpp"

class TestGame : public Game {
public:
	TestGame(const std::vector<PlayerPtr>& players, std::string name);
	~TestGame() override;

	void Start() override;
	void Rules() const override;
	void GameInfo(std::string n);

	TestGame& operator=(const Game& other);
};