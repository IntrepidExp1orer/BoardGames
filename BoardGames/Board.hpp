#pragma once
#include <vector>
#include <memory>
#include "Cell.hpp"

class Board {
private:
	int rows;
	int columns;
	std::vector<std::vector<Cell>> grid;
public:
	~Board() = default;

	Board(int row, int column);
	void Show();
	
	int GetValue(int row, int col);
	void SetValue(int row, int col, int value);
	int PointSum(int col);
};
