#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto t: times){
            int u,v,d;
            u = t[0];
            v = t[1];
            d = t[2];

            adj[u].push_back({v,d});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});

        while(not q.empty()){
            auto [d,u] = q.top();
            q.pop();

            if(dist[u] < d) continue;

            for(auto [v,nd]: adj[u]){
                if(d+nd < dist[v]){
                    dist[v] = d+nd;
                    q.push({d+nd,v});
                }
            }
        }

        int m = -1;

        for(int i=1;i<n+1;i++){
            if(dist[i] == INT_MAX) return -1;
            m = max(m, dist[i]);
        }

        return m;
    }
};