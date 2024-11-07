#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l<=r){
            if(not isalnum(s[l])) l++;
            else if(not isalnum(s[r])) r--;
            else if(tolower(s[l]) != tolower(s[r])) return false;
            else{
                l++;
                r--;
            }
        }

        return true;
    }
};