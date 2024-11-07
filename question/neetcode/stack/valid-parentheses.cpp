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
            if(not m.count(c)) st.push(c);
            else{
                if(st.size()==0 or m[c] != st.top()) return false;
                st.pop();
            }
        }

        return st.size()==0;
    }
};