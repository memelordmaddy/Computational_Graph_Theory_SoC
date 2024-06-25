#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<tuple<int, int, int>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(make_tuple(u,v,w));
    }
    int startindex;
    cin>>startindex;
    int distance[n];
    for(int i=0;i<n;i++)
    {
        distance[i] = INT_MAX;
    }
    distance[startindex]=0;
    for( int i=0; i<n-1; i++)
    {
        for(auto x: edges)
        {
            int u,v,w;
            tie (u,v,w) = x;
            distance[v] = min(distance[v], distance[u]+w);
        }
    }
    for(auto x: edges)
    {   int u, v, w;
        tie(u,v,w)=x;
        if(distance[v]>distance[u]+w)
        {
            cout<<"Negative cycle detected"<<endl;
            return 0;
        }
    }
    for( int i=0; i<n; i++)
    {   
        cout<<i<<" "<<distance[i]<<endl;
    }
    return 0;
}