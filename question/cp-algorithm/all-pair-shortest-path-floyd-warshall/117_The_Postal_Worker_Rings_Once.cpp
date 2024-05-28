#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

void addEdge(unordered_map<char, vector<pair<char, int>>> &graph, char start, char end, int cost) {
    graph[start].push_back({end, cost});
    graph[end].push_back({start, cost});
}

vector<char> findOddDegreeNodes(const unordered_map<char, int> &degrees) {
    vector<char> oddNodes;
    for (const auto &degree : degrees) {
        if (degree.second % 2 == 1) {
            oddNodes.push_back(degree.first);
        }
    }
    return oddNodes;
}

void addExtraEdge(unordered_map<char, vector<pair<char, int>>> &graph, const vector<char> &oddNodes) {
    if (oddNodes.size() == 2) {
        char u = oddNodes[0];
        char v = oddNodes[1];
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 0});
    }
}

int minimalTourCost(const unordered_map<char, vector<pair<char, int>>> &graph) {
    int minCost = INT_MAX;
    for (const auto &[node, edges] : graph) {
        for (const auto &[adjNode, cost] : edges) {
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int main() {
    string street;
    while (true) {
        unordered_map<char, vector<pair<char, int>>> graph;
        unordered_map<char, int> degrees;

        while (cin >> street && street != "deadend") {
            int cost = street.size();
            char start = street[0];
            char end = street.back();
            addEdge(graph, start, end, cost);
            degrees[start]++;
            degrees[end]++;
        }

        if (street.empty()) {
            break;
        }

        vector<char> oddNodes = findOddDegreeNodes(degrees);
        addExtraEdge(graph, oddNodes);

        int tourCost = minimalTourCost(graph);
        cout << tourCost << endl;
    }

    return 0;
}
