#pragma once
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Game.hpp"


class GameManager {
private:
	std::vector<Player> players;
public:
	GameManager() = default;
	~GameManager() = default;

	void Run();
	std::unique_ptr<Game> ChooseGame();
	void AddPlayers();
	std::vector<Player>& GetPlayerList();
};
