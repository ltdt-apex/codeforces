#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};


    int dfs(vector<vector<int>>& grid, int i, int j, unordered_map<int, unordered_set<int>>& seen, int n, int m){
        seen[i].insert(j);

        int area = 1;

        for (auto [di, dj]: dirs){
            int new_i = i+di;
            int new_j = j+dj;

            if(new_i<0 or new_i>=n or new_j<0 or new_j>=m or grid[new_i][new_j] == 0 or seen[new_i].count(new_j)) 
                continue;
            area += dfs(grid, new_i, new_j, seen, n, m);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*
        def dfs():
            area = 1

            for each cell next to it:
                if out of bound or the cell is not equal to 1 or the cell discover:
                    continue
                else:
                    area += dfs(cell)

            return area

        if cell = 1:
            dfs()
        
        */

        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, unordered_set<int>> seen;

        int maxArea = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and not seen[i].count(j)){
                    int area = dfs(grid,i,j,seen,n,m);
                    // cout << area << " " << endl;
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;

    }
};