#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n,m;
    vector<pair<int,int>> dirs = {{0,-1}, {0,1}, {-1,0}, {1,0}};
public:

    void dfs(int i, int j, vector<vector<int>>& seen, vector<vector<int>>& grid, int& s){
        seen[i][j] = 1;
        s++;
        
        for(auto [di,dj]: dirs){
            int ni=i+di;
            int nj=j+dj;
            
            if(ni<0 or nj<0 or ni>=n or nj>=m or grid[ni][nj]==0 or seen[ni][nj]) continue;
            dfs(ni,nj,seen,grid,s);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int a = 0;

        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> seen(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and not seen[i][j]){
                    int s = 0;
                    dfs(i,j,seen,grid,s);
                    a = max(a,s);
                }
            }
        }

        return a;
    }
};