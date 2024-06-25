#include<bits/stdc++.h>
using namespace std;
void dfs(int index, vector<int> adj[], bool visited[])
    {
        if(visited[index])
        {
            return;
        }
        else
        {
            visited[index] = true;
            cout<<index<<" ";
            for( auto x: adj[index])
            {
                dfs(x, adj, visited);
            }
        }
    }
int main()
{   int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int startindex;
    cin>>startindex;
    bool visited[n] = {false};
    dfs(startindex, adj, visited);
    

}