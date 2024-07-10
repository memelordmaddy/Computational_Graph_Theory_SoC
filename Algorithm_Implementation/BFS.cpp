#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
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
    queue<int> yet_to_visit;
    bool visited[n] = {false};
    int distance[n] = {0};
    yet_to_visit.push(startindex);
    distance[startindex] = 0;
    while(!yet_to_visit.empty())
    {
        int current = yet_to_visit.front();
        yet_to_visit.pop();
        visited[current] = true;

        for(auto x: adj[current])
        {
            if(!visited[x])
            {   visited[x]=true;
                yet_to_visit.push(x);
                distance[x] = distance[current] + 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
}