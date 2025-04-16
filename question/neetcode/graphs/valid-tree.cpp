#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int u, int p, vector<vector<int>>& adj, vector<int>& seen){
        seen[u] = 1;

        bool ok = true;

        for(auto v: adj[u]){
            if(p==v) continue;
            if(seen[v]) return false;
            ok &= dfs(v,u,adj,seen);
        }

        return ok;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> seen(n);

        return dfs(0,-1,adj,seen) and accumulate(seen.begin(), seen.end(), 0) == n;
    }
};
