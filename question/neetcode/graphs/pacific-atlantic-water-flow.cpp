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

    void dfs(int i, int j, vector<vector<int>>& heights, int n, int m, set<pair<int,int>>& seen){
        seen.insert({i,j});

        for(auto [di, dj]: dirs){
            int ni = i+di;
            int nj = j+dj;
            if(ni<0 or nj<0 or ni>=n or nj>=m or seen.count({ni,nj}) or heights[ni][nj]<heights[i][j]) continue;
            dfs(ni,nj,heights,n,m,seen);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        set<pair<int,int>> seen1;
        set<pair<int,int>> seen2;

        for(int i=0; i<n; i++){
            dfs(i,0,heights,n,m,seen1);
            dfs(i,m-1,heights,n,m,seen2);
        }
        for(int j=0; j<m; j++){
            dfs(0,j,heights,n,m,seen1);
            dfs(n-1,j,heights,n,m,seen2);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(seen1.count({i,j}) and seen2.count({i,j})){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};