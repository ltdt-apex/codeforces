#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;

        for(auto val: nums){
            q.push(val);
        }

        while(q.size()>k) q.pop();

        return q.top();
    }
};