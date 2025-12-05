using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public abstract class Game
{
    protected string currentGame;
    protected List<Player> players;

    public Game(List<Player> currentPlayers)
    {
        this.players = currentPlayers;
        this.currentGame = "Unnamed Game";
    }

    public abstract void Start();

    public List<Player> GetPlayerList()
    {
        return players;
    }
}
