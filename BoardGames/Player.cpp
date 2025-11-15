#include "Player.hpp"

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
