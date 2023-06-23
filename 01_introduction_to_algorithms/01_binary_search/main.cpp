#include <cstdint>
#include <cassert>
#include <vector>

template <typename T>
std::size_t binary_search(const std::vector<T>& vec, const T& item) {
	std::size_t low = 0;
	std::size_t high = vec.size() - 1;

	while (low <= high) {
		std::size_t middle = (low + high) / 2;
		const auto& guess = vec[middle];
		if (guess == item) {
			return middle;
		} else if (guess > item) {
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}

	return -1;
}

int main() {
	std::vector<int> vec = {1, 3, 5, 7, 9};

	assert(binary_search(vec, 1) == 0);
	assert(binary_search(vec, 3) == 1);
	assert(binary_search(vec, 9) == 4);
}