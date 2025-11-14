#pragma once
#include <array>
#include <iostream>
#include <vector>

class Dice {
private:
	std::array<int, 5> values;
public:
	Dice();
	~Dice() = default;

	void RollAll();
	void RollSelected(const std::vector<int>&);
	void Show();
	int Sum();
};