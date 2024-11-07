#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, unordered_set<int>& seen, int p){
        seen.insert(u);

        bool istree = true;

        for(auto v: adj[u]){
            if(v==p) continue;
            if(seen.count(v)) return false;
            istree &= dfs(v,adj,seen,u);
        }

        return istree;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> seen;

        return dfs(0,adj,seen,-1) and seen.size()==n;
    }
};
