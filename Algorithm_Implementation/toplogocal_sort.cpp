#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& inDegree) 
{
    int n = graph.size();
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < n; i++) 
    {
        if (inDegree[i] == 0) 
        {
            q.push(i);
        }
    }

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) 
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) 
            {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != n) 
    {
        result.clear();
    }

    return result;
}

int main() 
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> sortedNodes = topologicalSort(graph, inDegree);

    if (sortedNodes.empty()) 
    {
        cout << "The graph contains a cycle.\n";
    } 
    else 
    {
        cout << "Topological order: ";
        for (int node : sortedNodes) 
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
