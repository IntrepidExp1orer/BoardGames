#include <vector>
#include <sstream>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

Game::Game(const std::vector<PlayerPtr>& players, std::string name) : players(players), currentGame(name) {}


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

void Game::GameInfo() {
	std::cout << "Игра: " << currentGame;
}

std::string Game::WinnerName() {
	return winnerPlayer;
}

int Game::GetWinPoints() {
	return winPoints;
}

std::string Game::GetName() {
	return currentGame;
}
