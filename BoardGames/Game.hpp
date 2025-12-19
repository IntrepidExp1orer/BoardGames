#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Player.hpp"

class Game {

public:
	using PlayerPtr = std::shared_ptr<Player>;

	explicit Game(const std::vector<PlayerPtr>& players, std::string name);
	virtual ~Game() = default;

	virtual void Start() = 0;
	virtual void Rules() const;

	void Run();
	void GameInfo();
	const std::vector<PlayerPtr>& GetPlayerList() const;

	Game& operator=(const Game&) = delete;
protected:
	std::vector<PlayerPtr> players;
	std::string currentGame;
};