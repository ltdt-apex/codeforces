#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        /*
        queue = [(0,0,0)]

        seen 

        while queue is not empty:
            get cur cell and distance from front of queue

            for new cell in adj cells:
                if new cell container orange:
                    put (new cell and 1 + cur distance) in back of queue

        until queue is empty

        */

        queue<tuple<int,int,int>> q; // row, column, dist
        set<pair<int,int>> seen;
        int a = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    seen.insert({i,j});
                }
            }
        }

        while(not q.empty()){
            int i,j,d;
            tie(i,j,d) = q.front();
            q.pop();

            a = max(a,d);

            for (auto [di, dj]: dirs){
                int new_i = i+di;
                int new_j = j+dj;

                if(new_i<0 or new_i>=n or new_j<0 or new_j>=m or grid[new_i][new_j]==0 or seen.count({new_i, new_j})) continue;
                q.push({new_i,new_j,d+1});
                seen.insert({new_i,new_j});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0 and not seen.count({i,j})) return -1;
            }
        }

        return a;
    }
};