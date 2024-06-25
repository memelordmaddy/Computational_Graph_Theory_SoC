#include<bits/stdc++.h>
using namespace std;
void dfs(int child, int parent, int distance[],vector<int> adj[])
{   
    distance[child] = distance[parent]+1;
    for(auto x: adj[child])
    {
        if(x!=parent)
        {
            dfs(x,child,distance,adj);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++)
    {int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int distance[n+1]={0};
    distance[0]=-1;
    adj[0].push_back(1);
    dfs(1,0,distance,adj);
    int b=1, c=1;
    for(int i=1; i<=n; i++)
    {
        if(distance[i]>distance[b])
            {
                b=i;
                
            }
        distance[i]=0;
    }
    adj[0].pop_back();
    adj[0].push_back(b);
    dfs(b,0,distance, adj);
    for(int i=1; i<=n; i++)
    {
        if(distance[i]>distance[c])
            c=i;
    }
    cout<<distance[c];    
}