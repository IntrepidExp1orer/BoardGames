#include <vector>
#include <sstream>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

Game::Game(const std::vector<PlayerPtr>& players) : players(players) {}


const std::vector<std::shared_ptr<Player>>& Game::GetPlayerList() const {
    return players;
}

void Game::Rules() const {
	std::cout << "Общие правила данной игры:\n";
}

void Game::Run() {
	std::cout << "Запуск игры...\n\n";
	Start();
}
