#include "Player.hpp"

Player::Player(const std::string& name) : name(name), win_count(0) {
}

void Player::AddWin() {
	win_count += 1;
}

void Player::SetStats(int wins) {
	win_count = wins;
}


int Player::GetStats() {
	return win_count;
}

std::string Player::GetName() {
	return name;
}
