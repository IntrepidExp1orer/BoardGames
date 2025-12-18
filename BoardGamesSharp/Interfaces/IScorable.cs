using BoardGamesSharp.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Interfaces;

internal interface IScorable
{
    int CalculateScore(Player player);
    Player GetWinner();
}
