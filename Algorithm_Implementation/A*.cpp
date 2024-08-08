#include<bits/stdc++.h>
using namespace std;

// Define a structure for a node in the grid
struct Node {
    int x, y;
    int g; // Cost from start node
    int h; // Heuristic cost to goal
    int f; // Total cost (g + h)
    Node* parent;

    Node(int x, int y, int g, int h, Node* parent = nullptr) 
        : x(x), y(y), g(g), h(h), parent(parent), f(g + h) {}

    // Comparator for priority queue
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Heuristic function (Manhattan distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* algorithm function
vector<Node*> aStar(int startX, int startY, int goalX, int goalY, vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Node*, vector<Node*>, greater<Node*>> openList;
    unordered_map<int, Node*> allNodes;

    Node* start = new Node(startX, startY, 0, heuristic(startX, startY, goalX, goalY));
    openList.push(start);
    allNodes[startX * cols + startY] = start;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->x == goalX && current->y == goalY) {
            vector<Node*> path;
            while (current) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& dir : directions) {
            int newX = current->x + dir.first;
            int newY = current->y + dir.second;

            if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && grid[newX][newY] == 0) {
                int gNew = current->g + 1;
                int hNew = heuristic(newX, newY, goalX, goalY);
                int fNew = gNew + hNew;

                if (allNodes.find(newX * cols + newY) == allNodes.end() || fNew < allNodes[newX * cols + newY]->f) {
                    Node* neighbor = new Node(newX, newY, gNew, hNew, current);
                    openList.push(neighbor);
                    allNodes[newX * cols + newY] = neighbor;
                }
            }
        }
    }

    return {}; // Return empty if no path is found
}

int main() {
    int rows = 5;
    int cols = 5;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    // Set some obstacles
    grid[2][1] = grid[2][2] = grid[2][3] = 1;

    int startX = 0, startY = 0;
    int goalX = 4, goalY = 4;

    vector<Node*> path = aStar(startX, startY, goalX, goalY, grid);

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found:" << endl;
        for (const Node* node : path) {
            cout << "(" << node->x << ", " << node->y << ") ";
        }
        cout << endl;
    }

    return 0;
}
