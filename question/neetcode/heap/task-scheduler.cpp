#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_type(26);
        for(auto c: tasks){
            task_type[c-'A']++;
        }

        priority_queue<int> q;
        queue<pair<int,int>> cool_down;

        for(auto type: task_type){
            if (type != 0)
                q.push(type);
        };

        int t = 0;
        while(not q.empty() or not cool_down.empty()){
            // cout << q.size() << endl;
            if(not q.empty()){
                int remaining = q.top();
                q.pop();

                remaining--;
                if(remaining != 0){
                    cool_down.push({t+n, remaining});
                }
            }

            if(not cool_down.empty() and cool_down.front().first == t){
                int remaining = cool_down.front().second;
                cool_down.pop();

                q.push(remaining);
            }

            t++;
        }

        return t;
    }
};