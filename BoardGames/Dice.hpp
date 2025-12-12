#pragma once
#include <array>
#include <iostream>
#include <vector>

class Dice {
private:
	std::array<int, 5> values;
	static const int FACES = 6;
public:
	Dice();
	~Dice() = default;

	void RollAll();
	void RollSelected(const std::vector<int>&);
	int Sum();

	friend std::ostream& operator<<(std::ostream& os, const Dice& d);
};