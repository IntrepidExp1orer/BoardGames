#pragma once

class Cell {
private:
	int value;
public:
	Cell(int value = 0);
	
	int GetValue() const;
	void SetValue(int val);
	void Clear();
};
