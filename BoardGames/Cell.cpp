#include "Cell.hpp"

Cell::Cell(int val) : value(val) {}

int Cell::GetValue() const {
	return value;
}

void Cell::SetValue(int val) {
	value = val;
}

void Cell::Clear() {
	value = 0;
}
