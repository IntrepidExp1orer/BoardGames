#pragma once
#include <string>


class Player {
private:
	std::string name;
	int winCount;
public:
	Player() = default;
	explicit Player(const std::string& name);
	

	Player(const Player& other);

	void AddWin();
	void SetStats(int wins);
	int GetStats();
	std::string GetName();

	friend std::ostream& operator<<(std::ostream& os, const Player& p);
	friend bool operator==(const Player& a, const Player& b);
	friend bool operator<(const Player& a, const Player& b);
};