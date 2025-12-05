using System;
using System.Collections.Generic;
using System.Text;


using BoardGamesSharp.Core;

class Program
{
    static void Main(string[] args)
    {

        GameManager gManager = new GameManager();
        StatsManager sManager = new StatsManager("game_stats.txt");

        gManager.AddPlayers();
        List<Player> playerList = gManager.GetPlayerList();
        sManager.LoadStats(playerList);


        int menuChoice = 3;
        while(menuChoice != 0)
        {
            Console.WriteLine("\nВыберите действие:");
            Console.WriteLine("1. Статистика побед");
            Console.WriteLine("2. Выбор игры");
            Console.WriteLine("0. Выход");

            string choiceIn = Console.ReadLine();
            if (!int.TryParse(choiceIn, out menuChoice))
            {
                Console.WriteLine("Некорректный ввод. Попробуйте снова.");
                menuChoice = 3;
                continue;
            }


            switch (menuChoice)
            {
                case 1:
                    sManager.ShowStats();
                    break;
                case 2:
                    gManager.Run();
                    sManager.SaveStats(playerList);
                    break;
                case 0:
                    Console.WriteLine("Завершение работы.");
                    break;
                default:
                    break;
            }
        }
    }
}




