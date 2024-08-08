#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, index;
};

struct RevEdge {
    int source, index;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        map<int, vector<Edge>> edgesByWeight;
        for(int i = 0; i < m; ++i) {
            edgesByWeight[edges[i][2]].push_back({edges[i][0], edges[i][1], i});
        }

        vector<int> edgeStatus(m);
        vector<int> vertexColors(n);
        for(int i = 0; i < n; ++i) vertexColors[i] = i;

        int remainingEdges = n - 1;

        vector<vector<Edge>> graph(n);
        for(const auto& edgePair : edgesByWeight) {
            if(remainingEdges == 0) break;
            int weight = edgePair.first;
            const vector<Edge>& currentEdges = edgePair.second;
            for(const auto& edge : currentEdges) {
                if(vertexColors[edge.from] != vertexColors[edge.to]) {
                    graph[edge.from].push_back(edge);
                    graph[edge.to].push_back({edge.to, edge.from, edge.index});
                    edgeStatus[edge.index] = 1;
                    int oldColor = vertexColors[edge.to];
                    for(int i = 0; i < n; ++i)
                        if(vertexColors[i] == oldColor) vertexColors[i] = vertexColors[edge.from];
                    --remainingEdges;
                    continue;
                }
                vector<bool> visited(n);
                vector<RevEdge> predecessors(n);
                queue<int> q;
                q.push(edge.from);
                visited[edge.from] = true;
                while(!q.empty() && !visited[edge.to]) {
                    int node = q.front();
                    q.pop();
                    for(Edge conn : graph[node]) {
                        if(visited[conn.to]) continue;
                        visited[conn.to] = true;
                        predecessors[conn.to].source = node;
                        predecessors[conn.to].index = conn.index;
                        if(visited[edge.to]) break;
                        q.push(conn.to);
                    }
                }
                int node = edge.to;
                bool isSingleCycle = true;
                while(node != edge.from) {
                    if(edges[predecessors[node].index][2] == weight) {
                        edgeStatus[predecessors[node].index] = 2;
                        isSingleCycle = false;
                    }
                    node = predecessors[node].source;
                }
                if(!isSingleCycle) edgeStatus[edge.index] = 2;
            }
        }

        vector<int> criticalEdges, pseudoCriticalEdges;
        for(int i = 0; i < m; ++i)
            if(edgeStatus[i] == 1) criticalEdges.push_back(i);
            else if(edgeStatus[i] == 2) pseudoCriticalEdges.push_back(i);
        
        return {move(criticalEdges), move(pseudoCriticalEdges)};
    }
};
