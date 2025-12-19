using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Core;

public static class Utils
{
    public static T SumScores<T>(IEnumerable<T> values) where T : INumber<T>
    {
        T sum = T.Zero;
        foreach (var v in values)
        {
            sum += v;   
        }
        return sum;
    }
}
