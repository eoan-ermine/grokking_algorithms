#include <iostream>
#include <string_view>

void greet2(std::string_view name) {
	std::cout << "how are you, " << name << "?\n";
}

void bye() {
	std::cout << "ok bye!\n";
}

void greet(std::string_view name) {
	std::cout << "hello, " << name << "!\n";
	greet2(name);
	std::cout << "getting ready to say bye...\n";
	bye();
}

int main() {
	greet("john");
}