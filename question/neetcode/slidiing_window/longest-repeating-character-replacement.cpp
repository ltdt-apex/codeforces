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
        int max_ = 0;
        for(auto c: count){
            max_ = max(max_, c);
        }

        int total = right-left+1;

        return total - max_ <= k;
    }

    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0;

        vector<int> count(26);

        for(int right=0; right<s.size(); right++){
            count[s[right]-'A']++;
            while(left<=right and not canfit(count, left, right, k)){
                count[s[left]-'A']--;
                left++;
            }

            ans = max(ans, right-left+1);
        }


        return ans;
    }
};