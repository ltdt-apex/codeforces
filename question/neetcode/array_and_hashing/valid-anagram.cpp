#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);

        for(auto c: s){
            count[c-'a']++;
        }
        for(auto c: t){
            count[c-'a']--;
        }

        for(int i=0;i<26;i++){
            if(count[i]!=0) return false;
        }

        return true;
    }
};