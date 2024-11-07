#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> dirs = {{0,-1},{0,1},{1,0},{-1,0}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        q.push({grid[0][0], 0, 0});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        while(not q.empty()){
            int i,j,d;

            tie(d,i,j) = q.top();
            q.pop();

            if(i==n-1 and j==m-1) return d;

            if(dist[i][j] < d) continue;

            for(auto [di, dj]: dirs){
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 or nj<0 or ni>=n or nj>=m or max(d,grid[ni][nj]) >= dist[ni][nj]) continue;
                dist[ni][nj] = max(d,grid[ni][nj]);
                q.push({dist[ni][nj],ni,nj});
            }
        }

        return -1;
    }
};