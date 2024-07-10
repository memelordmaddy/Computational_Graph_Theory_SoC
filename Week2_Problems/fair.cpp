#include <bits/stdc++.h>
using namespace std;


int main() {

const int INF = (int)1e7;
const int MAXN = 100010;
const int MAXK = 302;

vector<int> adj[MAXN];
vector<int> colorNodes[MAXK];
int queue[MAXN];
int front;
int distances[MAXN];
int shortestPaths[MAXN][MAXK];
int nodes, edges, colors, minPaths;

    // Read input values
    cin >> nodes >> edges >> colors >> minPaths;

    // Read node colors and store them in colorNodes
    for (int i = 0; i < nodes; ++i) {
        int color;
        cin >> color;
        --color;
        colorNodes[color].push_back(i);
    }

    // Read edges and construct the adjacency list
    while (edges--) {
        int from, to;
        cin >> from >> to;
        --from; --to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    // Compute shortest paths for each color
    for (int color = 0; color < colors; ++color) {
        // Initialize distances to INF
        fill(distances, distances + nodes, INF);

        // Reset the queue
        front = 0;
        for (int node : colorNodes[color]) {
            distances[node] = 0;
            queue[front++] = node;
        }

        // BFS to find shortest paths
        for (int i = 0; i < front; ++i) {
            int currentNode = queue[i];
            for (int neighbor : adj[currentNode]) {
                if (distances[neighbor] > distances[currentNode] + 1) {
                    distances[neighbor] = distances[currentNode] + 1;
                    queue[front++] = neighbor;
                }
            }
        }

        // Store the computed distances in shortestPaths
        for (int i = 0; i < nodes; ++i) {
            shortestPaths[i][color] = distances[i];
        }
    }

    // Calculate the result for each node
    for (int i = 0; i < nodes; ++i) {
        nth_element(shortestPaths[i], shortestPaths[i] + minPaths, shortestPaths[i] + colors);
        int result = 0;
        for (int j = 0; j < minPaths; ++j) {
            result += shortestPaths[i][j];
        }
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
