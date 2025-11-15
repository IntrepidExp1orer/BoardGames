#pragma once
#include <vector>
#include "Player.hpp"

class StatsManager {
private:
	std::string filename;
	std::vector<Player> allPlayers;
public:
	StatsManager(const std::string& file);
	void LoadStats(std::vector<Player>& currentPlayers);
	void SaveStats(std::vector<Player>& currentPlayers);
	void ShowStats();
};
