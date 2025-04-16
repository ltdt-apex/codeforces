#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for(auto x: nums){
            m[x]++;
        }

        vector<pair<int,int>> c;

        for(auto [k,v]: m){
            c.push_back({v,k});
        }

        sort(c.rbegin(), c.rend());

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(c[i].second);
        }

        return ans;
    }
};