#include <iostream>
#include <vector>
#include "GameManager.hpp"
#include "YahtzeeGame.hpp"
#include "TestGame.hpp"
#include "StatsManager.hpp"


std::shared_ptr<Game> GameManager::Run() {
    auto currentGame = ChooseGame();

    if (!currentGame) {
        std::cout << "Выход из программы.\n";
        return nullptr;
    }
    else {
        totalGames++;
        currentGame->Run();
    }

    std::cout << "\nТекущие результаты после игры:\n";
    for (auto& p : players)
        std::cout << p->GetName() << ": " << p->GetStats() << "\n";

    return currentGame;
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
    std::cout << "2. Тест\n";
    std::cout << "3. (Пока не реализовано)\n";
    std::cout << "0. Выход\n";


    int gameChoice;
    std::cout << "\nВыберете игру: ";
    std::cin >> gameChoice;

    switch (gameChoice) {
    case 1:
        std::cout << "Хотите изменить число ходов? (Тек.: " << YahtzeeGame::GetHands() << ") ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int num = 0;
            while (num < 2 || num > 19) {
                std::cout << "Выберете число ходов (от 2 до 19): ";
                std::cin >> num;
            }
            YahtzeeGame::SetHands(num);
        }
        return std::make_unique<YahtzeeGame>(players, "Yahtzee");
    case 2:
        return std::make_unique<TestGame>(players, std::to_string(totalGames));
    case 0:
        return nullptr;
    default:
        std::cout << "Пока не реализовано.\n";
        return ChooseGame();
    }
}


