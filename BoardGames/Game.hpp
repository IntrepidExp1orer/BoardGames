#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Player.hpp"

class Game {

public:
	using PlayerPtr = std::shared_ptr<Player>;

	explicit Game(const std::vector<PlayerPtr>& players);
	virtual ~Game() = default;

	virtual void Start() = 0;
	virtual void Rules() const;

	void Run();

	const std::vector<PlayerPtr>& GetPlayerList() const;

protected:
	std::string currentGame;
	std::vector<PlayerPtr> players;
};