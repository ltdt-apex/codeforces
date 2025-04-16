#include <bits/stdc++.h>

using namespace std;

/*
s = "ADOBECODEBANC", t = "ABC"

m = {
    A: 1,
    B: 1,
    C: 1,
}

right
find A, m[A]--
find A, m[A]--

left
move until m[any]==0 

update ans if m[all]== 0

*/

class Solution {
public:

    bool contain(unordered_map<char,int>& cs, unordered_map<char,int>& ct){
        for(auto [k,v]: ct){
            if(cs[k]<ct[k]) return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> cs;
        unordered_map<char, int> ct;

        for(auto c: t){
            ct[c]++;
        }

        pair<int,int> ans = {0,n};
        int left = 0;

        for(int right=0;right<n;right++){
            cs[s[right]]++;
            while(cs[s[left]]>ct[s[left]]){
                cs[s[left]]--;
                left++;
            }

            if(contain(cs,ct) and ans.second-ans.first+1 > right-left+1){
                ans = {left,right};
            }
        }

        if(ans.second-ans.first+1==n+1){
            return "";
        }

        return s.substr(ans.first, ans.second-ans.first+1);
    }
};