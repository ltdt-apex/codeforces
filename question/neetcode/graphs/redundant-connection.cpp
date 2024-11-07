#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p;
    vector<int> size;

    DSU(int n): p(n+1), size(n+1){
        for(int i=1;i<n;i++) p[i]=i;
    }

    int find(int u){
        if(u==p[u]) return u;

        return p[u] = find(p[u]);
    }

    int same(int u, int v){
        return find(u) == find(v);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u==v) return;

        if(size[u]>size[v]) swap(u,v);
        p[u] = v;
        size[v]+=size[u];

    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto e: edges){
            if(dsu.same(e[0], e[1])) return {e[0], e[1]};
            dsu.join(e[0], e[1]);
        }

        return {};
    }
};