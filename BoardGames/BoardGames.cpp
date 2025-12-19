#include <iostream>
#include <Windows.h>
#include <limits>
#include <vector>
#include <algorithm>
#include "Player.hpp"
#include "Game.hpp"
#include "YahtzeeGame.hpp"
#include "Board.hpp"
#include "GameManager.hpp"
#include "StatsManager.hpp"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    GameManager gManager;
    StatsManager sManager("game_stats.txt");
    gManager.AddPlayers();
    auto playerList = gManager.GetPlayerList();
    sManager.LoadStats(playerList);

    std::vector<std::shared_ptr<Game>> gameHistory;
    std::shared_ptr<Game> finishedGame = nullptr;

    int menuChoice = 3;
    while (menuChoice != 0) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Статистика побед\n";
        std::cout << "2. Выбор игры\n";
        std::cout << "3. История игр за сессию\n";
        std::cout << "0. Выход\n";

        std::cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            sManager.ShowStats();
            break;
        case 2:
            finishedGame = gManager.Run();
            if (finishedGame) {
                gameHistory.push_back(finishedGame);
            }
            playerList = gManager.GetPlayerList();
            sManager.SaveStats(playerList);
            break;
        case 3:
            if (!sManager.FindYaht(gameHistory)) {
                std::cout << "Еще не было проведено игр.\n";
            }
            else {
                // Сортировка по набранным очкам
                std::sort(gameHistory.begin(), gameHistory.end(),
                    [](const std::shared_ptr<Game>& a, const std::shared_ptr<Game>& b) {
                            return a->GetWinPoints() > b->GetWinPoints();
                    }
                );

                // Вывод
                for (const auto& game : gameHistory) {
                    game->GameInfo();
                    std::cout << " | Победитель: " << game->WinnerName();
                    std::cout << " | Очки: " << game->GetWinPoints() << "\n";
                }
            }
            break;
        case 0:
            std::cout << "Завершение работы.\n";
            break;
        default:
            break;
        }
    }

    return 0;
}


