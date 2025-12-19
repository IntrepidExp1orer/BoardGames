#pragma once
#include <algorithm>
#include <memory>
#include <vector>
#include <array>
#include <concepts>
#include <numeric>

template <typename C>
auto SumScores(const C& container) {
    using T = typename C::value_type;
    static_assert(std::is_arithmetic_v<T>, "Container must hold numeric types");

    T sum{};
    for (const auto& v : container) {
        sum += v;
    }
    return sum;
}
