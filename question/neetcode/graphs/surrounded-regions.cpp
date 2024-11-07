#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void dfs(int i, int j, vector<vector<char>>& board, set<pair<int, int>>& seen, int n, int m){
        if(seen.count({i,j})) return;

        board[i][j] = 'Y';

        seen.insert({i,j});

        for(auto [di, dj]: dirs){
            int ni = i+di;
            int nj = j+dj;

            if(ni<0 or nj<0 or ni>=n or nj>=m or board[ni][nj] == 'X' or seen.count({ni,nj})) continue;
            dfs(ni,nj,board,seen,n,m);
        }
    }

    void solve(vector<vector<char>>& board) {
        set<pair<int,int>> seen;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,board,seen,n,m);
            if(board[i][m-1]=='O') dfs(i,m-1,board,seen,n,m);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,board,seen,n,m);
            if(board[n-1][j]=='O') dfs(n-1,j,board,seen,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};