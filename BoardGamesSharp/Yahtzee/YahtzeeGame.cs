using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BoardGamesSharp.Core;

namespace BoardGamesSharp.Yahtzee;

public class YahtzeeGame : Game
{
    private const int Hands = 6;

    private Dice dice = new Dice();

    public YahtzeeGame(List<Player> currentPlayers) : base(currentPlayers)
    {
        currentGame = "Yahtzee";
    }

    public override void Start()
    {
        Board scoreBoard = new Board(Hands + 1, players.Count);

        Console.WriteLine("\n----- Yahtzee -----");
        scoreBoard.Show();

        for (int i = 0; i < Hands; i++)
        {
            for (int j = 0; j < players.Count; j++)
            {
                Console.WriteLine($"\nИгрок {players[j].Name}:");
                dice.RollAll();
                dice.Show();
                ProcessMove();


                scoreBoard.SetValue(i, j, dice.Sum());
                scoreBoard.PointSum(j);
            }
            scoreBoard.Show();
        }

        int winner = 0;
        int winPoints = 0;
        bool draw = false;

        for (int j = 0; j < players.Count; j++)
        {
            int p = scoreBoard.GetValue(Hands, j);
            if (p == winPoints)
            {
                draw = true;
            }
            if (p > winPoints)
            {
                winPoints = p;
                winner = j;
                draw = false;
            }


            if (!draw)
            {
                players[winner].AddWin();
                Console.WriteLine($"Победил {players[winner].Name}");
            }
        }
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
                dice.RollSelected(indices);
                dice.Show();
                extraRolls--;
            }
        }
    }
}
