#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int al = 0;
        int ar = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0; j < n; j++){
                if(i-j<0 or i+j>=n) break;
                if(s[i-j]!=s[i+j])break;
                if(i+j-(i-j) > ar-al){
                    ar = i+j;
                    al = i-j;
                }
            }

        }

        for(int i = 0;i < n-1;i++){
            for(int j = 0; j < n; j++){
                if(i-j<0 or i+1+j>=n) break;
                if(s[i-j]!=s[i+1+j])break;
                if(i+1+j-(i-j) > ar - al){
                    ar = i+1+j;
                    al = i-j;
                }
            }
        }

        return s.substr(al,ar-al+1);
    }
};