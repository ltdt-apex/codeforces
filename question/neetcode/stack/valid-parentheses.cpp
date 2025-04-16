#include <bits/stdc++.h>

using namespace std;

/*
()[]{}
s = []
s = [(]
s = []

*/


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        stack<char> st;

        for(auto c: s){
            if(m.count(c)){
                if(st.empty() or st.top()!=m[c]) return false;
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        return st.size()==0;
    }
};