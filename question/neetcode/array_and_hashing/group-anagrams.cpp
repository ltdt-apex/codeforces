#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;

        for(string& s: strs){
            string k = s;
            sort(k.begin(), k.end());
            m[k].push_back(s);
        }

        vector<vector<string>> a;

        for(auto [k,v]: m){
            a.push_back(v);
        }

        return a;
    }
};