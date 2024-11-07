#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> d(n, INT_MAX);
        d[src] = 0;

        for(int i=0;i<k+1;i++){
            vector<int> nd(d);
            for(auto e: flights){
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if(d[u]!=INT_MAX and d[u]+w < nd[v]) nd[v] = d[u]+w;
            }

            d = move(nd);
        }

        if(d[dst] == INT_MAX) return -1;
        else return d[dst];
    }
};