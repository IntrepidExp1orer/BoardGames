#pragma once
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Game.hpp"


class GameManager {
public:
	using PlayerPtr = std::shared_ptr<Player>;

	GameManager() = default;
	~GameManager() = default;

	std::shared_ptr<Game> Run();
	std::unique_ptr<Game> ChooseGame();
	void AddPlayers();
	const std::vector<PlayerPtr>& GetPlayerList() const { return players; }
private:
	std::vector<PlayerPtr> players;
	std::unique_ptr<Game> currentGame;
	int totalGames = 0;
};
