#include "Dice.hpp"
#include "Utils.hpp"
#include <algorithm>


Dice::Dice() : values{1, 1, 1, 1, 1} {}

void Dice::RollAll() {
	std::transform(
		values.begin(),
		values.end(),
		values.begin(),
		[](int) {
			return rand() % FACES + 1;
		}
	);
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
	int s = SumScores(values);

	return s;
}
