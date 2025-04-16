#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(auto x:nums){
            if(s.count(x)) return 1;
            s.insert(x);
        }

        return 0;
    }
};