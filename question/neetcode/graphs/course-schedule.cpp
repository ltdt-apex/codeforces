#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> deg(n);

        int m = pre.size();
        for(int i=0;i<m;i++){
            int v = pre[i][0];
            int u = pre[i][1];

            adj[u].push_back(v);
            deg[v]++;
        }

        queue<int> q;
        int c = 0;

        for(int i=0;i<n;i++){
            if(deg[i]==0){
                q.push(i);                
            }
        }

        while(not q.empty()){
            int u = q.front(); q.pop();

            c++;

            for(auto v: adj[u]){
                deg[v]--;
                if(deg[v]==0) q.push(v);
            }
        }

        return c==n;
    }
};