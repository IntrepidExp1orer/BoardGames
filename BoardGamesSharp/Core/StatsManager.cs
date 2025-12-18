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

        try
        {
            if (File.Exists(filename))
            {
                using (StreamReader fin = new StreamReader(filename))
                {
                    string line;
                    while ((line = fin.ReadLine()) != null)
                    {
                        string[] lines = line.Split(' ');

                        if (lines.Length != 2 || !int.TryParse(lines[1], out int wins))
                        {
                            throw new FormatException("Неверный формат строки статистики");
                        }

                        string name = lines[0];
                        Player oldPlayer = new Player(name); 
                        oldPlayer.winCount = wins;
                        allPlayers.Add(oldPlayer);
                    }
                }
            }
        }

        catch (FileNotFoundException ex)
        {
            Console.WriteLine("Файл не найден. Будет создан новый.");
        }
        catch (FormatException ex)
        {
            Console.WriteLine("Файл поврежден.");
        }

        foreach (Player current in currentPlayers)
        {
            bool found = false;
            foreach (Player saved in allPlayers)
            {
                if (saved.name == current.name)
                {
                    current.winCount = saved.winCount;
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
                if (saved.name == current.name)
                {
                    saved.winCount = current.winCount;
                    break;
                }
            }
        }

        using (StreamWriter fout = new StreamWriter(filename))
        {
            foreach (Player player in allPlayers)
            {
                fout.WriteLine($"{player.name} {player.winCount}");
            }
        }
    }


    public void ShowStats()
    {
        Console.WriteLine("--- Статистика побед ---");
        foreach (Player player in allPlayers)
        {
            Console.WriteLine($"{player.name}: {player.winCount} побед");
        }
    }
}
