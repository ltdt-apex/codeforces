#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(auto x: nums) s.insert(x);

        int a = 0;
        for(auto x: s){
            if(s.count(x-1)) continue;
            int c = 0;

            int j=x;
            while(s.count(j)){
                c++;
                j++;
            }

            a = max(a,c);
        }

        return a;
    }
};