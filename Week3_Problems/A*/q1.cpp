/*
You are given any n*n grid in the form of a matrix where 0 represents no obstacle and 1 represents an obstacle. A start point and a goal point has been given. You can move in any four directions. Write a code for finding the shortest path using A* search algorithm.
*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
struct Node {
    int x, y; 
    int g;   
    int h;  
    int f;   

    Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), f(g + h) {}

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};
int heuristic(const Point& a, const Point& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
vector<Point> aStarSearch(const vector<vector<int>>& grid, const Point& start, const Point& goal) {
    int n = grid.size();
    int m = grid[0].size();

    priority_queue<Node, vector<Node>, greater<>> openList;
    unordered_set<int> closedSet;
    vector<vector<int>> gCost(n, vector<int>(m, INT_MAX));
    vector<vector<Point>> parent(n, vector<Point>(m, {-1, -1}));

    openList.push(Node(start.first, start.second, 0, heuristic(start, goal)));
    gCost[start.first][start.second] = 0;

    vector<Point> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();
        Point currentPoint = {current.x, current.y};

        if (currentPoint == goal) {
            vector<Point> path;
            for (Point p = goal; p != Point{-1, -1}; p = parent[p.first][p.second]) {
                path.push_back(p);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        closedSet.insert(current.x * m + current.y);

        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0) {
                int newG = current.g + 1;
                Point newPoint = {newX, newY};

                if (closedSet.find(newX * m + newY) != closedSet.end()) {
                    continue;
                }

                if (newG < gCost[newX][newY]) {
                    gCost[newX][newY] = newG;
                    int newH = heuristic(newPoint, goal);
                    openList.push(Node(newX, newY, newG, newH));
                    parent[newX][newY] = currentPoint;
                }
            }
        }
    }

    return {}; 
}
