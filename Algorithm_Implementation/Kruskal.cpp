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
int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w,a, b});
        edges.push_back({w,b, a});
    }
    vector<int> link(n), size(n, 1);
    for(int i = 0; i < n; i++) link[i] = i;
    sort(edges.begin(), edges.end());
    int min_cost = 0;
    //int count=0;
    for(auto [w, a, b] : edges){
        if(find(a, link) != find(b, link)){
            min_cost += w;
            //count++;
            unite(a, b, link, size);
        }
    }
    cout << min_cost << endl;

}