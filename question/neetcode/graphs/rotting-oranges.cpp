#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dirs = {{0,-1}, {0,1}, {-1,0}, {1,0}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        
        queue<tuple<int,int,int>> q;
        vector<vector<int>> seen(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)c++;
                if(grid[i][j] == 2) {
                    q.push({0,i,j});
                    seen[i][j] = 1;
                }
            }
        }
        int r = 0;
        int mt = 0;

        while(not q.empty()){
            int t,i,j;
            tie(t,i,j) = q.front(); q.pop();
            
            r++;
            mt = max(t,mt);

            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 or nj<0 or ni>=n or nj>=m or grid[ni][nj]!=1 or seen[ni][nj])continue;
                seen[ni][nj] = 1;
                q.push({t+1,ni,nj});
            }
        }

        if(c==r) return mt;
        else return -1;
    }
};