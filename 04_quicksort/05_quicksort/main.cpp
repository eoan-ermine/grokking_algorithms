#include <iostream>
#include <vector>

template <typename T>
std::vector<T> quicksort(const std::vector<T>& arr) {
    if (arr.size() < 2) 
        return arr;
    
    const T& pivot = arr[arr.size() / 2];
    std::vector<T> less;
    std::vector<T> greater;

    for (const auto& item: arr) {
        if (item == pivot) continue; // skip pivot element
        if (item <= pivot) less.push_back(item);
        else greater.push_back(item);
    }
    
    std::vector<T> sorted_less = quicksort(less);
    std::vector<T> sorted_greater = quicksort(greater);
    sorted_less.push_back(pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
    
    return sorted_less;
}

int main() {
	std::vector<float> arr = {1.2, 1.0, 3, 0, -1, 0.5, 100, -99};
	std::vector<float> sorted = quicksort(arr);

	std::cout << "Sorted array: ";
	for (float num : sorted) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}