#pragma once
#include <vector>
#include "Player.hpp"
#include "Game.hpp"

class TestGame : public Game {
public:
	TestGame(const std::vector<PlayerPtr>& players);
	~TestGame() override;

	void Start() override;
	void Rules() const override;

};