#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};

class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& seen, int n, int m){
        seen[i][j] = 1;

        for(auto [di,dj]: dirs){
            int ni = i+di;
            int nj = j+dj;

            if(ni<0 or nj<0 or ni>=n or nj>=m or grid[ni][nj]=='0' or seen[ni][nj]) continue;
            dfs(ni,nj,grid,seen,n,m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int a = 0;
        vector<vector<int>> seen(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and not seen[i][j]){
                    a++;
                    dfs(i,j,grid,seen,n,m);
                }
            }
        }

        return a;
    }
};