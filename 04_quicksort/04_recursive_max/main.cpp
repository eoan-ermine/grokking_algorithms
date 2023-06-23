#include <iostream>
#include <vector>
#include <span>

template <typename T>
T max(std::span<T> arr) {
	if (arr.size() == 1) {
		return arr[0];
	}

	auto maximum = max(std::span<T>(arr.begin() + 1, arr.end()));
	if (arr[0] > maximum) {
		return arr[0];
	}
	return maximum;

}

int main() {
	std::vector<int> arr{5, 4, 3, 2, 1};
	std::cout << max<int>(arr) << std::endl;
}