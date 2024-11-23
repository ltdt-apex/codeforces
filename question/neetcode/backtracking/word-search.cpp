#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};

    void dfs(int i, int j, int k, vector<vector<char>>& board, string& word, vector<vector<int>>& seen, bool& found, int n, int m){
        if(board[i][j] != word[k]) return;

        // cout << k << " " << endl;

        if(k==word.size()-1){
            found = true;
            return;
        }

        seen[i][j] = 1;

        for(auto [di, dj]: dirs){
            int ni = i+di;
            int nj = j+dj;

            if(ni<0 or nj<0 or ni>=n or nj>=m or seen[ni][nj] == 1) continue;

            dfs(ni,nj,k+1,board,word,seen,found,n,m);
        }

        seen[i][j] = 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool found = false;
        vector<vector<int>> seen(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,0,board,word,seen,found,n,m);
            }
        }

        return found;
    }
};