#include <sstream>
#include <iostream>
#include "TestGame.hpp"

TestGame::TestGame(const std::vector<PlayerPtr>& players) : Game(players) {}

TestGame::~TestGame() {
    std::cout << "TestGame destroyed\n";
}


void TestGame::Start() {
    std::cout << "Запуск тестовой игры\n";
}

void TestGame::Rules() const {
    std::cout << "Тестовая игра, правил нет.\n";
}