#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        for(auto c: tasks){
            v[c-'A']++;
        }

        priority_queue<int> q;
        queue<pair<int,int>> cd;

        for(int i=0;i<26;i++){
            if(v[i]!=0) q.push(v[i]);
        }

        int a = 0;

        while(not q.empty() or not cd.empty()){
            if(not q.empty()){
                int r = q.top(); q.pop();
                r--;
                if(r!=0) cd.push({a+n,r});
            }

            while(not cd.empty() and cd.front().first == a){
                auto [_,r] = cd.front(); cd.pop();
                q.push(r);
            }

            a++;
        }

        return a;
    }
};