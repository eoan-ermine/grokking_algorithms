#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

std::unordered_set<std::string> operator & (
	const std::unordered_set<std::string>& a, const std::unordered_set<std::string>& b) {
	std::unordered_set<std::string> result;
	for (const auto& i : a)
		for (const auto& j : b)
			if (i == j)
				result.insert(i);
	return result;
}

void operator -= (
	std::unordered_set<std::string>& a, const std::unordered_set<std::string>& b) {
	for (auto j = b.begin(); j != b.end(); ++j)
		for (auto i = a.begin(); i != a.end(); )
			if (*i == *j) i = a.erase(i);
			else ++i;
}

int main() {
	auto states_needed = std::unordered_set<std::string>{
		"mt", "wa", "or", "id", "nv", "ut", "ca", "az"
	};
	std::unordered_map<std::string, std::unordered_set<std::string>> stations;
	std::unordered_set<std::string> final_stations;

	stations["kone"] = {"id", "nv", "ut"};
	stations["ktwo"] = {"wa", "id", "mt"};
	stations["kthree"] = {"or", "nv", "ca"};
	stations["kfour"] = {"nv", "ut"};
	stations["kgive"] = {"ca", "az"};

	while (!states_needed.empty()) {
		std::string best_station;
		std::unordered_set<std::string> states_covered;
		for (const auto& [station, states]: stations) {
			auto covered = states_needed & states;
			if (covered.size() > states_covered.size()) {
				best_station = station;
				states_covered = covered;
			}
		}
		states_needed -= states_covered;
		final_stations.insert(best_station);	
	}
	for (const auto& i : final_stations)
		std::cout << i << std::endl;
}