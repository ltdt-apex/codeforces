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
    string minWindow(string s, string t) {
        int ansl = 0;
        int ans = INT_MAX;
        int left = 0;

        unordered_map<char, int> counts;
        for(auto c: t){
            counts[c]++;
        }

        for(int right = 0; right < s.size(); right++){
            if(counts.count(s[right])){
                counts[s[right]]--;
            }

            while(left <= right and (not counts.count(s[left]) or counts[s[left]] < 0)){
                if(counts.count(s[left])){
                    counts[s[left]]++;
                }
                left++;
            }

            bool isVaild = 1;
            for(auto [k,v]: counts){
                if(v>0) isVaild = 0;
            }

            if(isVaild and right-left+1 < ans){
                ans = right-left+1;
                ansl = left;
            }

        }

        if(ans == INT_MAX) return "";
        return s.substr(ansl, ans);
    }
};