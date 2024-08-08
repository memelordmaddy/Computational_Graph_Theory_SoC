#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = numeric_limits<int>::max();
        vector<int> dist(n, INF);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist; 
            for (const auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if (dist[from] != INF && dist[from] + price < temp[to]) {
                    temp[to] = dist[from] + price;
                }
            }
            dist = temp;  
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};
