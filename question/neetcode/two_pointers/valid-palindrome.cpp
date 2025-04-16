#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = s.size()-1;

        while(l<=r){
            while (l<r and not isalnum(s[l])) l++;
            while (l<r and not isalnum(s[r])) r--;

            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }

        return true;
    }
};