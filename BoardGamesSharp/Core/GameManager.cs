using BoardGamesSharp.Yahtzee;
using System;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public class GameManager
{
    private List<Player> players = new List<Player>();

    public void Run()
    {
        Game currentGame = ChooseGame();

        if (currentGame == null) { Console.WriteLine("Не удалось запустить игру."); }
        else
        {
            Console.WriteLine("Запуск игры...\n");
            currentGame.Start();
        }


        Console.WriteLine("Текущие результаты после игры: ");
        foreach(Player player in players)
        {
            Console.WriteLine($"{player.Name}: {player.Wins}");
        }
    }

    public void AddPlayers()
    {
        int count = -1;
        while (count <= 0)
        {
            Console.Write("Введите количество игроков: ");
            string countStr = Console.ReadLine();
            if (!int.TryParse(countStr, out count) || count <= 0) { Console.WriteLine("Некорректный ввод."); }
        }

        players.Clear();
        for (int i = 0; i < count; i++)
        {
            Console.Write($"Имя игрока {i + 1}: ");
            string name = Console.ReadLine();
            players.Add(new Player(name));
        }
    }

    private Game ChooseGame()
    {
        Console.WriteLine("\nВыберите игру:");
        Console.WriteLine("1. Yahtzee");
        Console.WriteLine("2. (Пока не реализовано)");
        Console.WriteLine("0. Выход");

        int gameChoice = 0;
        Console.Write("Выберете игру: ");
        string gameChoiceStr = Console.ReadLine();
        if (!int.TryParse(gameChoiceStr, out gameChoice)) 
        { 
            Console.WriteLine("Некорректный ввод.");
        }

        switch (gameChoice)
        {
            case 0: return null;
            case 1: 
                return new YahtzeeGame(players);
            default: 
                Console.WriteLine("Пока не реализовано.");
                return ChooseGame();
        }
        return null;
    }

    public List<Player> GetPlayerList() { return players; }
}
