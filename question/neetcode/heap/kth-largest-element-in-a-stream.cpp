#include <bits/stdc++.h>
using namespace std;

/*
[4,5] 1 push
[2,4,5] 1 push and pop
[2,4,5] 3 push and pop

*/


class KthLargest {
    private:
        int k;
        priority_queue<int, vector<int>, greater<int>> q;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for(auto x: nums){
                q.push(x);
            }

            while(q.size()>k){
                q.pop();
            }
        }
        
        int add(int val) {
            q.push(val);

            if(q.size()>k) q.pop();

            return q.top();
        }
    };
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */