#pragma once
#include <vector>
#include <memory>
#include "Cell.hpp"

class Board {
private:
	int rows;
	int columns;
	std::vector<std::vector<std::shared_ptr<Cell>>> grid;
public:
	~Board() = default;

	Board(int row, int column);

	Board(const Board& saveState) = delete;
	Board& operator=(const Board&) = delete;

	std::shared_ptr<Board> ShallowClone() const;
	std::shared_ptr<Board> DeepClone() const;

	
	int GetValue(int row, int col);
	void SetValue(int row, int col, int value);
	int PointSum(int col);

	friend std::ostream& operator<<(std::ostream& os, const Board& b);
};
