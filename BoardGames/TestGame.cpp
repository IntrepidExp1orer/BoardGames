#include <sstream>
#include <iostream>
#include "TestGame.hpp"

TestGame::TestGame(const std::vector<PlayerPtr>& players, std::string name) : Game(players, name) {}

TestGame::~TestGame() {
    std::cout << "TestGame destroyed\n";
}


void TestGame::Start() {
    GameInfo(currentGame);
}

void TestGame::Rules() const {
    std::cout << "Тестовая игра, правил нет.\n";
}

TestGame& TestGame::operator=(const Game& other) {
    if (this == &other) return *this;
    return *this;
}


void TestGame::GameInfo(std::string n) {
    std::cout <<  "Тест производного класса. Вызов игры #" << currentGame;
}
