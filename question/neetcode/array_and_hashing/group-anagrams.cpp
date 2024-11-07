#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(auto s: strs){
            string ori = s;
            sort(s.begin(), s.end());
            m[s].push_back(ori);
        }

        vector<vector<string>> ans;

        for(auto [k,v]: m){
            ans.push_back(v);
        }

        return ans;
    }
};