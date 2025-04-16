#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    void dfs(int n1, int n2, int n, string& cur, vector<string>& ans){
        if(n1==n and n2==n){
            ans.push_back(cur);
            return;
        }

        if(n1<n){
            cur.push_back('(');
            dfs(n1+1,n2,n,cur,ans);
            cur.pop_back();
        }

        if(n2<n1){
            cur.push_back(')');
            dfs(n1,n2+1,n,cur,ans);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> ans;

        dfs(0,0,n,cur,ans);

        return ans;
    }
};
