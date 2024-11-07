#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int u, vector<vector<int>>& adj, vector<int>& seen, vector<int>& ans){
        seen[u] = 1;

        for(auto v: adj[u]){
            if(not seen[v]) dfs(v,adj,seen,ans);
        }

        ans.push_back(u);
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> seen(n);
        vector<int> ans;

        for(auto p: pre){
            adj[p[0]].push_back(p[1]);
        }

        for(int i=0; i<n; i++){
            if(not seen[i]) dfs(i,adj,seen,ans);
        }

        vector<int> depth(n);
        for(int i=0;i<n;i++){
            depth[ans[i]] = i;
        }

        for(int u=0; u<n; u++){
            for(auto v: adj[u]){
                if(depth[v]>depth[u]) return {};
            }
        }

        return ans;
    }
    // kahn's algorithm(bfs)
    // vector<int> findOrder(int n, vector<vector<int>>& pre) {
    //     stack<int> s;

    //     vector<int> req(n);
    //     vector<vector<int>> adj(n);
    //     for(auto p: pre){
    //         req[p[0]]++;
    //         adj[p[1]].push_back(p[0]);
    //     }

    //     vector<int> ans;

    //     for(int i=0;i<n;i++){
    //         if(req[i]==0) s.push(i);
    //     }

    //     while(not s.empty()){
    //         int u = s.top();
    //         s.pop();
    //         ans.push_back(u);

    //         for(auto v: adj[u]){
    //             req[v]--;
    //             if(req[v]==0) s.push(v);
    //         }

    //     }

    //     if(ans.size()!=n) return {};
    //     return ans;
    // }
};