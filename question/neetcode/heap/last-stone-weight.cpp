#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;

        for(auto x: stones){
            q.push(x);
        }

        while(q.size()>=2){
            int a = q.top();q.pop();
            int b = q.top();q.pop();

            if(a==b) continue;
            else{
                q.push(a-b);
            }
        }

        if(q.size()==0) return 0;
        else return q.top();
    }
};