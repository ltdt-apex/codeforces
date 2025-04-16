#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        3
        0 1 2 3
          3 2 1 0
        */
        int n = nums.size();

        vector<int> pre;
        pre.push_back(1);
        for(int i=0;i<n;i++){
            pre.push_back(pre.back()*nums[i]);
        }
        vector<int> post;
        post.push_back(1);
        for(int i=n-1;i>=0;i--){
            post.push_back(post.back()*nums[i]);
        }


        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i] = pre[i]*post[n-i-1];
        }

        return a;
    }
};