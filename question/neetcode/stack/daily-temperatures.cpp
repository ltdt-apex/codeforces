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

        stack<pair<int, int>> s;
        vector<int> ans(n, 0);

        for(int i=0;i<n;i++){
            int cur = temperatures[i];

            while(not s.empty() and cur > s.top().first){
                int d = i - s.top().second;
                ans[s.top().second] = d;
                s.pop();
            }
            s.push({cur,i});
        }

        return ans;
    }
};