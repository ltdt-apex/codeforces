#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        temp = [73,74,75,71,69,72,76,73]
        answer = [1,1,4,2,1,1,0,0]

        stack = [(73,0),...,] 74,i
        stack = [(86,j)]

        [7,6,8]
        [2,1,0]

        [7,6,8]
        */

        int n = temperatures.size();
        vector<int> ans(n,0);

        stack<pair<int,int>> s;

        for(int i=0;i<n;i++){
            int t = temperatures[i];

            while(not s.empty() and s.top().second < t){
                auto [pi, pt] = s.top(); s.pop();
                ans[pi] = i-pi;
            }

            s.push({i,t});
        }

        return ans;
    }
};