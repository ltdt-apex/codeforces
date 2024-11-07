#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> required(numCourses);
        vector<int> count(numCourses);

        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
            required[pre[1]]++;
        }

        queue<int> q;
        int finished = 0;

        for(int i=0;i<numCourses;i++){
            if(required[i]==0) {
                q.push(i);
                finished++;
            }
        }

        while(not q.empty()){
            int course = q.front();
            q.pop();
            for(auto next: adj[course]){
                count[next]++;
                if(count[next] == required[next]){
                    q.push(next);
                    finished++;
                }
            }
        }

        return finished == numCourses;
    }
};