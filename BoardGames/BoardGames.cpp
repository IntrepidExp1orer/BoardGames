#include <iostream>
#include <Windows.h>
#include <limits>
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


    int menuChoice = 3;
    while (menuChoice != 0) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Статистика побед\n";
        std::cout << "2. Выбор игры\n";
        std::cout << "0. Выход\n";

        std::cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            sManager.ShowStats();
            break;
        case 2:
            gManager.Run();
            playerList = gManager.GetPlayerList();
            sManager.SaveStats(playerList);
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


