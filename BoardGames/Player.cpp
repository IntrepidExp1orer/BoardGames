#include "Player.hpp"
#include <ostream>

Player::Player(const std::string& name) : name(name), winCount(0) {
}


void Player::AddWin() {
	winCount += 1;
}

void Player::SetStats(int wins) {
	winCount = wins;
}


int Player::GetStats() {
	return winCount;
}

std::string Player::GetName() {
	return name;
}


std::ostream& operator<<(std::ostream& os, const Player& p) {
	os << p.name << " (" << p.winCount << " wins)";
	return os;
}

bool operator==(const Player& a, const Player& b) {
	return a.name == b.name;
}

bool operator<(const Player& a, const Player& b) {
	return a.winCount < b.winCount;
}
