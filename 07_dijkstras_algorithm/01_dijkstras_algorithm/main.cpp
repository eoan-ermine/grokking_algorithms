#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <limits>

int main() {
	using node_t = std::string;
	using cost_graph_t = std::unordered_map<node_t, unsigned>;
	using graph_t = std::unordered_map<node_t, cost_graph_t>;
	using parent_graph_t = std::unordered_map<node_t, node_t>;

	// Setup graph
	graph_t graph;
	graph.reserve(4);
	graph.emplace("start", cost_graph_t{{"a", 6}, {"b", 2}});
	graph.emplace("a", cost_graph_t{{"finish", 1}});
	graph.emplace("b", cost_graph_t{{"a", 3},{"finish", 5}});
	graph.emplace("finish", cost_graph_t{});
	// Setup costs table
	cost_graph_t costs{{"a", 6},{"b", 2},{"finish", std::numeric_limits<unsigned>::max()}};
	// Setup parents table
	parent_graph_t parents{{"a", "start"}, {"b", "start"}};

	std::vector<node_t> processed;
	const auto find_min_cost_node = [&processed](const cost_graph_t& costs) {
		auto lowest_cost = std::numeric_limits<unsigned>::max();
		node_t lowest_cost_node{};

		for (const auto& [node, cost]: costs) {
			bool isNotProcessed = std::find(processed.cbegin(), processed.cend(), node) == processed.cend();
			if (cost < lowest_cost && isNotProcessed) {
				lowest_cost = cost;
				lowest_cost_node = node;
			}
		}

		return lowest_cost_node;
	};

	auto node = find_min_cost_node(costs);
	while (!node.empty()) {
		const auto current_cost = costs[node];
		const auto& neighbours = graph[node];

		for (const auto& [name, cost]: neighbours) {
			const auto new_cost = current_cost + cost;
			if (new_cost < costs[name]) {
				costs[name] = new_cost;
				parents[name] = node;
			}
		}
		processed.push_back(node);
		node = find_min_cost_node(costs);
	}

	std::cout << "Cost from the start to each node:" << std::endl;
	for (const auto& [name, cost] : costs)
	{
		std::cout << name << " " << cost << std::endl;
	}
}