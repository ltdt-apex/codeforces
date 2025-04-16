#include <bits/stdc++.h>

using namespace std;

/*
dfs:
ldtr

dp grid save pair init -1,-1

smaller stop
if dp not empty return
if i==0 or j==0 set first 1
if i==n or j==m, set second 1

find 1,1 at the end.

*/

class Solution {
public:

    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int i, int j, vector<vector<int>>& seen, vector<vector<int>>& heights, int n, int m){
        seen[i][j] = 1;

        for(auto [di, dj]: dirs){
            int ni = i+di;
            int nj = j+dj;

            if(ni<0 or nj<0 or ni>=n or nj>=m or seen[ni][nj] or heights[i][j] > heights[ni][nj]) continue;

            dfs(ni,nj,seen,heights,n,m);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> seen1(n, vector<int>(m));
        vector<vector<int>> seen2(n, vector<int>(m));

        for(int i=0;i<n;i++){
            dfs(i,0,seen1,heights,n,m);
            dfs(i,m-1,seen2,heights,n,m);
        }

        for(int j=0;j<m;j++){
            dfs(0,j,seen1,heights,n,m);
            dfs(n-1,j,seen2,heights,n,m);
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(seen1[i][j] == 1 and seen2[i][j] == 1)ans.push_back({i,j});
            }
        }

        return ans;
    }
};