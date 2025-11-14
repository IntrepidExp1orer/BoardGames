#include <vector>
#include "Game.hpp"
#include "Player.hpp"

Game::Game(std::vector<Player>& currentPlayers) : players(currentPlayers) {}


std::vector<Player> Game::GetPlayerList() {
	return players;
}
