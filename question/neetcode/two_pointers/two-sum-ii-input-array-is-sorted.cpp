#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n-1;

        while(true){
            if(numbers[l] + numbers[r] == target) return {l+1,r+1};
            else if (numbers[l] + numbers[r] < target) l++;
            else r--;
        }
    }
};