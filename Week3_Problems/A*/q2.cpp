/*
In the Q1 replace the grid with an undirected graph where weights might be negative. Write a code for finding the shortest path using A* search algorithm.
*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int vertex;
    int g;
    int h;
    int f;

    Node(int vertex, int g, int h) : vertex(vertex), g(g), h(h), f(g + h) {}

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

int heuristic(int a, int b) {
    return abs(a - b);
}

vector<int> aStarSearch(int n, const vector<vector<pair<int, int>>>& graph, int start, int goal) {
    priority_queue<Node, vector<Node>, greater<>> openList;
    unordered_set<int> closedSet;
    vector<int> gCost(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);

    openList.push(Node(start, 0, heuristic(start, goal)));
    gCost[start] = 0;

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();
        int u = current.vertex;

        if (u == goal) {
            vector<int> path;
            for (int v = goal; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        closedSet.insert(u);

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            int newG = gCost[u] + weight;

            if (closedSet.find(v) != closedSet.end()) {
                continue;
            }

            if (newG < gCost[v]) {
                gCost[v] = newG;
                int newH = heuristic(v, goal);
                openList.push(Node(v, newG, newH));
                parent[v] = u;
            }
        }
    }

    return {};
}
