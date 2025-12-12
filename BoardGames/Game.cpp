#include <vector>
#include "Game.hpp"
#include "Player.hpp"

Game::Game(const std::vector<PlayerPtr>& players) : players(players) {}


const std::vector<std::shared_ptr<Player>>& Game::GetPlayerList() const {
    return players;
}



