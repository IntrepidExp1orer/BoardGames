using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BoardGamesSharp.Yahtzee;

public class Dice
{
    private int[] values = new int[5];
    private const int Faces = 6;

    private static Random random = new Random();

    public Dice()
    {
        for (int i = 0; i < values.Length; i++)
        {
            values[i] = 1;
        }
    }


    public void RollAll()
    {
        for (int i = 0;i < values.Length; i++)
        {
            values[i] = random.Next(1, Faces + 1);
        }
    }

    public void RollSelected(List<int> indices)
    {
        foreach (int index in indices)
        {
            if (index >= 0 && index < values.Length) {
                values[index] = random.Next(1, Faces + 1);
            }
        }
    }


    public void Show()
    {
        Console.WriteLine($"[{string.Join(" ", values)}]");
    }


    public int Sum()
    {
        return values.Sum();
    }
}
