using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BoardGamesSharp.Core;
using BoardGamesSharp.Interfaces;

namespace BoardGamesSharp.Yahtzee;

public class YahtzeeGame : Game, IRollable, IScorable
{
    private const int Hands = 6;

    private Dice dice = new Dice();

    private Board scoreBoard;
    private bool drawStatus = false;

    public YahtzeeGame(List<Player> currentPlayers) : base(currentPlayers)
    {
        currentGame = "Yahtzee";
        scoreBoard = new Board(Hands + 1, players.Count);
    }

    public override void Start()
    {
        // Board scoreBoard = new Board(Hands + 1, players.Count);

        Console.WriteLine("\n----- Yahtzee -----");
        scoreBoard.Show();

        for (int i = 0; i < Hands; i++)
        {
            for (int j = 0; j < players.Count; j++)
            {
                Console.WriteLine($"\nИгрок {players[j].name}:");
                Roll();
                ProcessMove();


                scoreBoard.SetValue(i, j, dice.Sum());
                scoreBoard.PointSum(j);
            }
            scoreBoard.Show();
        }

        Player winner = GetWinner();
        if (!drawStatus && winner != null)
        {
            winner.AddWin();
            Console.WriteLine($"Победил {winner.name}");
        }
        else
        {
            Console.WriteLine("Ничья");
        }
    }

    public Player GetWinner()
    {
        int winPoints = 0;
        Player winner = null;

        foreach (var player in players)
        {
            int score = CalculateScore(player);
            if (score == winPoints)
            {
                drawStatus = true;
            }
            else if (score > winPoints)
            {
                winPoints = score;
                winner=player;
                drawStatus = false;
            }
        }

        return winner;
    }

    public int CalculateScore(Player player)
    {
        int index = players.IndexOf(player);
        return scoreBoard.GetValue(Hands, index);
    }

    public void ProcessMove()
    {
        int extraRolls = 2;
        while (extraRolls > 0)
        {
            Console.WriteLine("Хотите перебросить некоторые кубики? (y/n)");
            string choice = Console.ReadLine();
            if (choice.ToLower() == "n" || string.IsNullOrEmpty(choice)) break;

            Console.WriteLine("Введите номера кубиков для переброса (1-5, через пробел):");
            string chosenLine = Console.ReadLine();

            List<int> indices = new List<int>();
            string[] parts = chosenLine.Split(' ', StringSplitOptions.RemoveEmptyEntries);

            foreach (string part in parts)
            {
                if (int.TryParse(part, out int diceIndex))
                {
                    indices.Add(diceIndex - 1);
                }
            }


            if (indices.Count > 0)
            {
                Roll(indices);
                extraRolls--;
            }
        }
    }


    public void Roll(List<int> indices)
    {
        dice.RollSelected(indices);
        dice.Show();
    }

    public void Roll()
    {
        dice.RollAll();
        dice.Show();
    }

    public override void PrintRules()
    {
        base.PrintRules();
        Console.WriteLine("Игроки по очереди бросают кубики до трех раз за ход.\nПри перебросе можно выбрать какие кубики оставить.\nЦель - выбить максимум очков.\n");
    }
}



