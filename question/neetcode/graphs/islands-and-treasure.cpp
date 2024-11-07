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

        queue<tuple<int,int,int>> q; // (row no., column no., distance to the closest treasure)
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, unordered_set<int>> seen;

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) {
                    q.push({i,j,0});
                    seen[i].insert(j);
                }
            }
        }

        while(not q.empty()){
            int i,j,d;
            tie(i,j,d) = q.front();
            q.pop();

            grid[i][j] = d;

            for (auto [di, dj]: dirs){
                int new_i = i+di;
                int new_j = j+dj;

                // cout << new_i << " " << new_j << " " << seen[new_i].count(new_j) << endl;
                if(new_i<0 or new_i>=n or new_j<0 or new_j>=m or grid[new_i][new_j]==-1 or seen[new_i].count(new_j)) continue;

                // cout << new_i << " " << new_j << endl;
                q.push({new_i, new_j, 1+d});
                seen[new_i].insert(new_j);
            }
        }
    }
};
