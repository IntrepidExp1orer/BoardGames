#include <iomanip>
#include <iostream>
#include "Board.hpp"


Board::Board(int row, int column) : rows(row), columns(column) {
	grid.resize(rows, std::vector<Cell>(columns, Cell(0)));
}


void Board::Show() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			std::cout << std::setw(6) << grid[r][c].GetValue();
		}
		std::cout << "\n";
	}
}


int Board::GetValue(int row, int col) {
	if (row >= 0 && row < rows && col >= 0 && col < columns) return grid[row][col].GetValue();
}


void Board::SetValue(int row, int col, int val) {
	if (row >= 0 && row < rows && col >= 0 && col < columns) grid[row][col].SetValue(val);
}


int Board::PointSum(int col) {
	if (col < 0 || col >= columns) return 0;

	int PSum = 0;
	for (int i = 0; i < rows - 1; i++) {
		PSum += grid[i][col].GetValue();
	}

	grid[rows-1][col].SetValue(PSum);
	return PSum;
}
