#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;

        for (auto x: nums){
            count[x]++;
        }

        set<pair<int,int>> heap;

        for(auto [k,v]: count){
            heap.insert({-v,k});
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back((*heap.begin()).second);
            heap.erase(heap.begin());
        }

        return ans;
    }
};