#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool updateMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool updateMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

int numNodes, numEdges;
vector<vector<int>> adjacencyList;
int memo[100100];

int findLongestPath(int node) {
    if (memo[node] != -1) return memo[node];

    int maxLength = 0;
    for (auto neighbor : adjacencyList[node]) {
        updateMax(maxLength, findLongestPath(neighbor) + 1);
    }
    return memo[node] = maxLength;
}

int main() {
    cin >> numNodes >> numEdges;
    adjacencyList.assign(numNodes, vector<int>());
    for (int i = 0; i < numEdges; ++i) {
        int from, to; cin >> from >> to;
        --from, --to;
        adjacencyList[from].push_back(to);
    }

    for (int i = 0; i < numNodes; ++i) memo[i] = -1;

    int longestPath = 0;
    for (int i = 0; i < numNodes; ++i) updateMax(longestPath, findLongestPath(i));
    cout << longestPath << endl;
}
