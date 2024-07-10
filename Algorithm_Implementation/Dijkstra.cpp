#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int, int>> adj[n];
    for(int i=0; i<m; i++)
    {int a, b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    priority_queue<pair<int, int>> pq;
    int distance[n];
    for(int i=0; i<n; i++)
    {
        distance[i] = INT_MAX;
    }
    int startindex;
    cin>>startindex;
    distance[startindex] = 0;
    pq.push({0,startindex});
    bool visited[n] = {false};
    while(!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();
        if(visited[current])
        {
            continue;
        }
        visited[current] = true;
        for(auto x: adj[current])
        {   
            int b,w;
            tie(b,w)=x;
            if(distance[b]>distance[current]+w)
            {
                distance[b] = distance[current]+w;
                pq.push({-distance[b],b});
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
}