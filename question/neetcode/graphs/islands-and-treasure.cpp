#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
        queue = [(0,2,0), (3,0,0)]

        create ans matrix
        create queue

        while queue is not empty:
            get cur cell from the front of queue
            update cell distance

            for each new cell in top down left right:
                if new cell not valid: continue
                    put new cell (i,j,1+cur cell distance) into the queue for next search

        return ans
        */
       int n=grid.size();
       int m = grid[0].size();
       vector<vector<int>> seen(n, vector<int>(m));
       queue<tuple<int,int,int>> q;

       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({0,i,j});
                    seen[i][j] = 1;
                }
            }
       }


       while(not q.empty()){
            int d,i,j;
            tie(d,i,j) = q.front(); q.pop();

            grid[i][j] = d;

            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 or nj<0 or ni>=n or nj>=m or grid[ni][nj]==-1 or seen[ni][nj]) continue;
                seen[ni][nj] = 1;
                q.push({d+1,ni,nj});
            }
       }
    }
};
