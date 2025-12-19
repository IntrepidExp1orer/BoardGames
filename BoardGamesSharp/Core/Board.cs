using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace BoardGamesSharp.Core;

public class Board : ICloneable
{
    private int rows;
    private int columns;
    private Cell[,] grid;

    public Board(int row, int column) 
    {  
        rows = row; 
        columns = column; 
        grid = new Cell[rows, columns];

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                grid[r, c] = new Cell();
            }
        }
    }


    public void Show()
    {
        for(int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns ; c++)
            {
                Console.Write($"{grid[r, c].val,6}");
            }
            Console.WriteLine();
        }
    }

    public int GetValue(int row, int column)
    {
        if (row < 0 || row >= rows) return 0;
        else if (column < 0 || column >= columns) return 0;
        else return grid[row, column].val;
    }


    public void SetValue(int row, int column, int val)
    {
        if (row >= 0 && row < rows)
        if (column >= 0 && column < columns)
        grid[row, column].val = val;
    }


    public int PointSum(int column)
    {
        if (column < 0 || column >= columns) return 0;

        var values = new List<int>();

        for (int i = 0; i < rows - 1; i++)
        {
            values.Add(grid[i, column].val);
        }

        int pointSum = Utils.SumScores(values);

        grid[rows-1, column].val = pointSum;
        return pointSum;
    }

    public object Clone()
    {
        return (Board)this.MemberwiseClone();
    }

    public object DeepClone()
    {
        return new Board(rows, columns);
    }
}


