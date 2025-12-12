#include <iostream>
#include <vector>
#include "GameManager.hpp"
#include "YahtzeeGame.hpp"
#include "StatsManager.hpp"


void GameManager::Run() {
    currentGame = ChooseGame();

    if (!currentGame) {
        std::cout << "Выход из программы.\n";
    }
    else {
        std::cout << "Запуск игры...\n\n";
        currentGame->Start();
    }

    std::cout << "\nТекущие результаты после игры:\n";
    for (auto& p : players)
        std::cout << p->GetName() << ": " << p->GetStats() << "\n";
}

void GameManager::AddPlayers() {
    int count;
    std::cout << "Введите количество игроков: ";
    std::cin >> count;
    players.clear();

    for (int i = 0; i < count; i++) {
        std::string name;
        std::cout << "Имя игрока " << i + 1 << ": ";
        std::cin >> name;
        players.push_back(std::make_shared<Player>(name));
    }
}



std::unique_ptr<Game> GameManager::ChooseGame() {
    std::cout << "\nВыберите игру:\n";
    std::cout << "1. Yahtzee\n";
    std::cout << "2. (Пока не реализовано)\n";
    std::cout << "0. Выход\n";


    int gameChoice;
    std::cout << "\nВыберете игру: ";
    std::cin >> gameChoice;

    switch (gameChoice) {
    case 1:
        return std::make_unique<YahtzeeGame>(players);
    case 0:
        return nullptr;
    default:
        std::cout << "Пока не реализовано.\n";
        return ChooseGame();
    }
}


