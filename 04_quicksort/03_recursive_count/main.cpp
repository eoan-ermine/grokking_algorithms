#include <iostream>
#include <vector>
#include <span>

template <typename T>
std::size_t count(std::span<T> arr) {
	if (arr.size() == 0) {
		return 0;
	}
	return 1 + count(
		std::span<T>{arr.begin() + 1, arr.end()}
	);
}

int main() {
	std::vector<int> arr{1, 2, 3, 4, 5};
	std::cout << count<int>(arr) << std::endl;
}