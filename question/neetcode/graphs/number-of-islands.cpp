#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(set<pair<int, int>>& seen, int i, int j, int n, int m, vector<vector<char>>& grid){
        seen.insert({i,j});

        for(auto [di, dj]: dirs){
            int ni = i + di;
            int nj = j + dj;
            if(ni<0 or nj<0 or ni>=n or nj>=m or grid[ni][nj]=='0' or seen.count({ni,nj})) continue;

            dfs(seen, ni ,nj, n, m, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        set<pair<int, int>> seen;
        int n = grid.size();
        int m = grid[0].size();

        int a = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='1' and not seen.count({i,j})){
                    dfs(seen, i, j, n, m, grid);
                    a++;
                }
            }
        }
        return a;
    }
};