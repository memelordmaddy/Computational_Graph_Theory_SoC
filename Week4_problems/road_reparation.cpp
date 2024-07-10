// https://cses.fi/problemset/task/1675/
#include<bits/stdc++.h>
using namespace std;

int find(int a, vector<int> &link){
    while(a != link[a]) a = link[a];
    return a;
}
void unite(int a, int b, vector<int> &link, vector<int> &size){
    a = find(a, link);
    b = find(b, link);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}
void dfs(int index, vector<int> adj[], bool visited[])
    {
        if(visited[index])
        {
            return;
        }
        else
        {
            visited[index] = true;
            //cout<<index<<" ";
            for( auto x: adj[index])
            {
                dfs(x, adj, visited);
            }
        }
    }
bool check_connected_graph(vector<tuple<int, int,long long int>> edges, int n){
    vector<int> adj[n];
    for( auto x: edges)
    {
        int a, b, w;
        tie(w, a, b) = x;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int startindex=0;
    bool visited[n]={false};
    dfs(startindex, adj, visited);
    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, long long int>> edges;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w,a-1, b-1});
        edges.push_back({w,b-1, a-1});
    }
    if(!check_connected_graph(edges, n))
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> link(n), size(n, 1);
    for(int i = 0; i < n; i++) link[i] = i;
    sort(edges.begin(), edges.end());
    long long int min_cost = 0;
    //int count=0;
    for(auto [w, a, b] : edges){
        if(find(a, link) != find(b, link)){
            min_cost += w;
            //count++;
            unite(a, b, link, size);
        }
    }
    cout << min_cost;

}