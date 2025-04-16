#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> s;

    DSU(int n): parent(n), s(n,1) {
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    int same(int u, int v){
        return find(u) == find(v);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u==v) return;

        if(s[u]>s[v]) swap(u,v);

        parent[u] = v;
        s[v] += s[u];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n+1);

        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            if(dsu.same(u,v)) return {u,v};
            dsu.join(u,v);
        }

        return {};
    }
};