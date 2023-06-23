#include <iostream>

void countdown(int i) {
	std::cout << i << '\n';
	if (i <= 0)
		return;
	else
		countdown(i - 1);
}

int main() {
	countdown(5);
}