#pragma once

class Cell {
private:
	int value;
public:
	Cell(int value = 0);
	
	int GetValue();
	void SetValue(int val);
	void Clear();
};
