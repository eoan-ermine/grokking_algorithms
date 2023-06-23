#include <iostream>

long long factorial(int x) {
	if (x == 1)
		return 1;
	else
		return x * factorial(x - 1);
}

int main() {
	std::cout << "factorial of 5 is " << factorial(5) << '\n';
}