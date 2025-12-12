using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public class Cell(int v = 0)
{
    public int val { get; set; } = v;

    public void Clear() { val = 0; }
}
