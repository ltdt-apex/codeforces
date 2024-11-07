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
    vector<int> size;
    int groups;

    DSU(int n): parent(n), size(n,1), groups(n){
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }

    void join(int i, int j){
        i = find(i);
        j = find(j);

        if (i==j) return;

        if(size[i] > size[j]){
            swap(i,j);
        }

        parent[i] = j;
        size[j] += size[i];
        groups--;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto e: edges){
            dsu.join(e[0], e[1]);
        }

        return dsu.groups;
    }
};
