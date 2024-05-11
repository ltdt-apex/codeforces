#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> d = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        stack<char> st;

        for (auto c:s){
            if (d.count(c)){
                if(st.empty() or d[c] != st.top()){
                    return false;
                }
                st.pop();
            }
            else
                st.push(c);
        }

        return st.empty();
    }
};