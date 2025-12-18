#include <iomanip>
#include <iostream>
#include "Board.hpp"


Board::Board(int row, int column) : rows(row), columns(column) {
	// grid.resize(rows, std::vector<Cell>(columns, Cell(0)));

	grid.resize(rows);
	for (int i = 0; i < rows; ++i) {
		grid[i].resize(columns);
		for (int j = 0; j < columns; ++j) {
			grid[i][j] = std::make_shared<Cell>(0);
		}
	}
}

Board::Board(const Board& saveState) : rows(saveState.rows), columns(saveState.columns), grid(saveState.grid) {}

std::ostream& operator<<(std::ostream& os, const Board& board) {
	for (int r = 0; r < board.rows; r++) {
		for (int c = 0; c < board.columns; c++) {
			os << std::setw(6) << board.grid[r][c]->GetValue();
		}
		os << "\n";
	}
	return os;
}


int Board::GetValue(int row, int col) {
	if (row < 0 || row > rows) return 0;
	else if (col < 0 || col > columns) return 0;
	else return grid[row][col]->GetValue();
}


void Board::SetValue(int row, int col, int val) {
	if (row >= 0 || row < rows)
	if (col >= 0 || col < columns)
	grid[row][col]->SetValue(val);
}


int Board::PointSum(int col) {
	if (col < 0 || col >= columns) return 0;

	int pointSum = 0;
	for (int i = 0; i < rows - 1; i++) {
		pointSum += grid[i][col]->GetValue();
	}

	grid[rows-1][col]->SetValue(pointSum);
	return pointSum;
}

std::shared_ptr<Board> Board::ShallowClone() const {
	return std::make_shared<Board>(*this);
}


std::shared_ptr<Board> Board::DeepClone() const {
	auto clone = std::make_shared<Board>(rows, columns);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			clone->grid[i][j] = std::make_shared<Cell>(*grid[i][j]);
		}
	}

	return clone;
}
