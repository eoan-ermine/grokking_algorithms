#include <iostream>
#include <vector>

template <typename T>
T sum(const std::vector<T>& arr) {
	T total = 0;
	for (const auto& element: arr) {
		total += x;
	}
	return total;
}

int main() {
	std::cout << sum({1, 2, 3, 4, 5}) << std::endl;
}