#include <iostream>
#include <cstdint>
#include <vector>

template <typename T>
std::size_t find_smallest(const std::vector<T>& vec) {
	T smallest = vec[0];
	std::size_t smallest_index = 0;
	for (int i = 1, size = vec.size(); i != size; ++i) {
		if (vec[i] < smallest) {
			smallest = vec[i];
			smallest_index = i;
		}
	}
	return smallest_index;
}

template <typename T>
std::vector<T> selection_sort(std::vector<T> vec) {
	std::vector<T> new_vec;
	new_vec.reserve(vec.size());

	while (!vec.empty()) {
		std::size_t smallest_index = find_smallest(vec);
		new_vec.push_back(vec[smallest_index]);
		vec.erase(vec.begin() + smallest_index);
	}

	return new_vec;
}

int main() {
	std::vector<float> arr = {1.2, 1.0, 3, 0, -1, 0.5, 100, -99};
	std::vector<float> sorted = selection_sort(arr);

	std::cout << "Sorted array: ";
	for (float num : sorted) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}