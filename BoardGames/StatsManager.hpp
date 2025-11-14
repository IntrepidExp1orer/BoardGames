#pragma once
#include <vector>
#include "Player.hpp"

class StatsManager {
private:
	std::string filename;
	std::vector<Player> all_players;
public:
	StatsManager(const std::string& file);
	void LoadStats(std::vector<Player>& current_players);
	void SaveStats(std::vector<Player>& current_players);
	void ShowStats();
};
