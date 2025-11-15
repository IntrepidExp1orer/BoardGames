#pragma once
#include <string>

class Player {
private:
	std::string name;
	int winCount;
public:
	Player() = default;
	~Player() = default;

	Player(const std::string& name);
	void AddWin();
	void SetStats(int wins);
	int GetStats();
	std::string GetName();
};