#pragma once
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Game.hpp"

class StatsManager {
private:
	std::string filename;
	std::vector<std::shared_ptr<Player>> allPlayers;
public:
	StatsManager(const std::string& file);
	void LoadStats(std::vector <std::shared_ptr<Player>>& currentPlayers);
	void SaveStats(const std::vector<std::shared_ptr<Player>>& currentPlayers);
	void ShowStats();
	bool FindYaht(std::vector<std::shared_ptr<Game>> gameHistory);
};
