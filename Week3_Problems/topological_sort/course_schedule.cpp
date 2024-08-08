#include<bits/stdc++.h>
using namespace std;
class Solver {
public:
    int numNodes;
    vector <vector<int>> graph;
    unordered_map<int, bool> state;
    vector<int> result;
    
    bool depthFirstSearch(int node) {
        if (state.find(node) != state.end()) {
            return state[node];
        }
        
        state[node] = false;

        for (auto& neighbor : graph[node]) {
            if (!depthFirstSearch(neighbor)) {
                return state[node] = false;
            }
        }
        
        result.push_back(node);
        return state[node] = true;
    }

    vector<int> findOrdering(int n, vector<vector<int>>& edges) {
        this->numNodes = n;
        if (n == 1) {
            return {0};
        }
        
        this->graph.resize(n);
        for (const auto& edge : edges) {
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (state.find(i) == state.end()) {
                depthFirstSearch(i);
            }
            if (state[i] == false) {
                return {};
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
