//https://codeforces.com/problemset/problem/1775/D
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s,t;
    cin>>s>>t;
    sort(a.begin(), a.end());
    vector<bool> is_prime(a[n - 1] + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= a[n - 1]; i++)
    {
        if (is_prime[i])
        {   primes.push_back(i);
            for (int j = i * 2; j <= a[n - 1]; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    int k=primes.size();
    vector<int> adj[n+k];
    for(auto x:primes)
    {
        for(auto y: a)
        {
            if(y%x==0)
            {
                adj[y-1].push_back(x-1+k);
                adj[x-1+k].push_back(y-1);
            }
        }
    }
    int startindex=s-1;
    n=n+k;
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
    cout<<distance[t-1];

}