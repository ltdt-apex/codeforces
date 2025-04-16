#include <bits/stdc++.h>

using namespace std;

/*
s = "AABABBA", k = 1

m = {
    A: 3
    B: 1
}

left = 0
right = 3
total - max = 4-1 = 3

*/ 

class Solution {
public:

    bool canfit(vector<int>& count, int left, int right, int k){
        int m = right-left+1;

        int max_ = 0;
        for(auto x: count){
            max_ = max(max_, x);
        }

        return m-max_<=k;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int ans = 0;

        vector<int> count(26);

        for(int right=0;right<n;right++){
            count[s[right]-'A']++;
            while(not canfit(count, left, right, k)){
                count[s[left]-'A']--;
                left++;
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};