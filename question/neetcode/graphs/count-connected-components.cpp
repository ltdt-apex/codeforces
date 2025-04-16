#include <bits/stdc++.h>

using namespace std;

/*
dsu
1-2-3-4
4-5

[1,2], [3,4], [2,3], 

1234

*/
struct DSU {
    int n;
    vector<int> parent;
    vector<int> s;
    int group;

    DSU(int n): n(n), parent(n), s(n,1), group(n) {
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }

    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u==v) return;

        if(s[u]>s[v]) swap(u,v);

        parent[u] = v;
        s[v]+=s[u];
        group--;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto e: edges){
            dsu.join(e[0], e[1]);
        }

        return dsu.group;
    }
};
