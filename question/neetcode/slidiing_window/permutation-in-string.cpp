#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool issame(vector<int>& count1, vector<int>& count2){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]) return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        /*
        s1 = "ab" s1.size = 2

        "ab"

        "ei"

        1e 1i
        1d 1i

        s2 = "eidbaooo"

        s1 = "ab"
        s2 = "eidboaoo"

        s1 = ""
        */

        int n = s1.size();
        vector<int> count1(26);

        for(int i=0;i<n;i++){
            count1[s1[i]-'a']++;
        }

        int m = s2.size();
        vector<int> count2(26);

        for(int r=0;r<m;r++){
            count2[s2[r]-'a']++;

            if(r+1>=n){
                if (issame(count1, count2)) return true;
                count2[s2[r+1-n]-'a']--;
            }
        }

        return false;
    }
};