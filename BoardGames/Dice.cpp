#include "Dice.hpp"


Dice::Dice() : values{1, 1, 1, 1, 1} {}

void Dice::RollAll() {
	for (int& i : values) {
		int n = rand() % FACES + 1;
		i = n;
	}
}

void Dice::RollSelected(const std::vector<int>& indices) {
	for (int i : indices) {
		if (i > 0 && i < FACES) values[i-1] = rand() % FACES + 1;
	}
}


std::ostream& operator<<(std::ostream& os, const Dice& dice) {
	os << "[";
	for (int i : dice.values) {
		os << " " << i ;
	}
	os << " ]";
	return os;
}

int Dice::Sum() {
	int s = 0;
	for (int i : values) {
		s += i;
	}
	return s;
}
