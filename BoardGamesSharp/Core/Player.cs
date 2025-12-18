using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public class Player
{
    public string name { get; }
    public int winCount { get; set; }

    public Player(string name)
    {
        this.name = name;
        winCount = 0;
    }

    public void AddWin() {
        winCount++;
    }

}
