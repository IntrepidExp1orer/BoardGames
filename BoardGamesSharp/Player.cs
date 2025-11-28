using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public class Player
{
    private string name;
    private int winCount;

    public Player(string in_name)
    {
        name = in_name;
        winCount = 0;
    }

    public void AddWin() {
        winCount++;
    }

    public int Wins
    {
        get { return winCount; }
        set { winCount = value; }
    }   

    public string Name
    {
        get { return name; }
    }
}
