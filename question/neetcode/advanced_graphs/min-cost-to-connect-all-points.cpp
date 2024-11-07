#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p;
    vector<int> size;

    DSU(int n): p(n), size(n){
        for(int i=0;i<n;i++){
            p[i]=i;
        }
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
        size[v] += size[u];
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<tuple<int,int,int>> edges;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;

                int p1i = points[i][0];
                int p1j = points[i][1];
                int p2i = points[j][0];
                int p2j = points[j][1];

                edges.push_back({abs(p1i-p2i)+abs(p1j-p2j),i,j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int ans = 0;

        for(auto e: edges){
            int d,i,j;
            tie(d,i,j) = e;

            if(dsu.same(i,j)) continue;
            dsu.join(i,j);
            ans += d;
        }

        return ans;
    }
};