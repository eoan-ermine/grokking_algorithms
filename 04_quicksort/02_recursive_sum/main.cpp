#include <iostream>
#include <vector>
#include <span>

template <typename T>
T sum(std::span<T> arr) {
	if (arr.size() == 0) {
		return 0;
	}
	return arr[0] + sum(
		std::span<T>{arr.begin() + 1, arr.end()}
	);
}

int main() {
	std::vector<int> arr{1, 2, 3, 4, 5};
	std::cout << sum<int>(arr) << std::endl;
}