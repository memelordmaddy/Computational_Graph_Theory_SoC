#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int, int>> adj[n];
    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    bool added[n]={0};
    int min_cost=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int a=pq.top().second;
        int w=-pq.top().first;
        pq.pop();
        if(added[a]) continue;
        min_cost+=w;
        added[a]=1;
        for(auto x: adj[a])
        {
            if(!added[x.first])
            {
                pq.push({-x.second, x.first});
            }
        }
    }
    cout<<min_cost<<endl;
}