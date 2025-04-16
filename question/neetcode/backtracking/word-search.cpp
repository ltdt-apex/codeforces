#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dirs = {{0,-1}, {0,1}, {-1,0}, {1,0}};

class Solution {
    public:
        bool dfs(int k, int i, int j, int n, int m, vector<vector<char>>& board, string& word, vector<vector<int>>& seen){
            if(board[i][j]!=word[k]){
                return false;
            }

            if(k==word.size()-1){
                return true;
            }
            
            bool ans = false;
            seen[i][j] = 1;
            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;
                
                if(ni<0 or nj<0 or ni>=n or nj>=m or seen[ni][nj]) continue;
                ans |= dfs(k+1,ni,nj,n,m,board,word,seen);
            }
            seen[i][j] = 0;

            return ans;
        }

        bool exist(vector<vector<char>>& board, string word) {
            int n = board.size();
            int m = board[0].size();

            vector<vector<int>> seen(n, vector<int>(m));

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(dfs(0,i,j,n,m,board,word,seen)) return true;
                }
            }

            return false;
        }
    };