#pragma once
#include <string>
#include <vector>
#include "Player.hpp"

class Game {
protected:
	std::string currentGame;
	std::vector<Player>& players;
public:
	explicit Game(std::vector<Player>& currentPlayers);
	virtual ~Game() = default;

	virtual void Start() = 0;
	std::vector<Player> GetPlayerList();
};