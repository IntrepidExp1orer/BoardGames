using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Interfaces
{
    internal interface IRollable
    {
        void Roll(List<int> indices);
    }
}
