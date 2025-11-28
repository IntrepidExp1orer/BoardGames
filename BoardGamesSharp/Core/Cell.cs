using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public class Cell(int v = 0)
{
    private int val = v;

    public int Val
    {
        get { return val; }
        set { val = value; }
    }

    public void Clear() { val = 0; }
}
