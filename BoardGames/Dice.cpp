#include "Dice.hpp"


Dice::Dice() : values{1, 1, 1, 1, 1} {}

void Dice::RollAll() {
	for (int& i : values) {
		int n = rand() % 6 + 1;
		i = n;
	}
}

void Dice::RollSelected(const std::vector<int>& indices) {
	for (int i : indices) {
		if (i > 0 && i < 6) values[i-1] = rand() % 6 + 1;
	}
}

void Dice::Show() {
	std::cout << "[";
	for (int i : values) {
		std::cout << i << "  ";
	}
	std::cout << "]\n";
}

int Dice::Sum() {
	int s = 0;
	for (int i : values) {
		s += i;
	}
	return s;
}
