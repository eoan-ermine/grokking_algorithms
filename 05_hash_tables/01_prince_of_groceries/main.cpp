#include <unordered_map>
#include <string>

using std::cout;
using std::endl;

int main() {
    std::unordered_map<std::string, float> book = {
        {"apple", 0.67},
        {"milk", 1.49},
        {"avocado", 1.49}
    };

    for (const auto& [name, price] : book) {
        cout << name << ": " << price << "$" << endl;
    }
}