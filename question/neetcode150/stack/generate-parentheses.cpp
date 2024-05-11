#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int l, int r, stack<char>& cur, vector<string>& ans){
        if(not l and not r){
            string a;
            stack<char> temp = cur;
            while (not temp.empty()){
                a += temp.top();
                temp.pop();
            }
            reverse(a.begin(), a.end());
            ans.push_back(a);
        }
        if(l){
            cur.push('(');
            dfs(l-1, r, cur, ans);
            cur.pop();
        }

        if(r and r > l){
            cur.push(')');
            dfs(l, r-1, cur, ans);
            cur.pop();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> s;
        dfs(n,n,s,ans);

        return ans;
    }
};