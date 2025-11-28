using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

internal class StatsManager
{
    private string filename;
    private List<Player> allPlayers = new List<Player>();

    public StatsManager(string file)
    {
        this.filename = file;
    }

    public void LoadStats(List<Player> currentPlayers)
    {
        allPlayers.Clear();

        if (File.Exists(filename))
        {
            using (StreamReader fin = new StreamReader(filename))
            {
                string line;
                while ((line = fin.ReadLine()) != null)
                {
                    string[] lines = line.Split(' ');
                    string name = lines[0];
                    Player oldPlayer = new Player(name);
                    int.TryParse(lines[1], out int wins);
                    oldPlayer.Wins = wins;
                    allPlayers.Add(oldPlayer);
                }
            }
        }


        foreach (Player current in currentPlayers)
        {
            bool found = false;
            foreach (Player saved in allPlayers)
            {
                if (saved.Name == current.Name)
                {
                    current.Wins = saved.Wins;
                    found = true;
                    break;
                }
            }

            if (!found) allPlayers.Add(current);
        }
    }


    public void SaveStats(List<Player> currentPlayers)
    {
        foreach (Player current in currentPlayers)
        {
            foreach (Player saved in allPlayers)
            {
                if (saved.Name == current.Name)
                {
                    saved.Wins = current.Wins;
                    break;
                }
            }
        }

        using (StreamWriter fout = new StreamWriter(filename))
        {
            foreach (Player player in allPlayers)
            {
                fout.WriteLine($"{player.Name} {player.Wins}");
            }
        }
    }


    public void ShowStats()
    {
        Console.WriteLine("--- Статистика побед ---");
        foreach (Player player in allPlayers)
        {
            Console.WriteLine($"{player.Name}: {player.Wins} побед");
        }
    }
}
