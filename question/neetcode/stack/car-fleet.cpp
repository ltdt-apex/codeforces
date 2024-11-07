#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
        p = [7,6,5]
        s = [1,2,3]

        p = [5,6,7]
        s = [3,2,1]

        p = [1,3,4]
        t = [3,5,7]

        time = (t-p)/s

        (time,position) sort ascending order of time, then ascending order position
        (1,2), (1,10)


        tp = [(1,2), (5,10), (10,0), (20,11)]

        # no of group, and also final time required
        stack = [(5,10), (10,0)]
        */

        int n = position.size();

        vector<double> time(n);
        vector<pair<double,int>> time_positional(n);

        for(int i=0;i<n;i++){
            time_positional[i] = {double(target-position[i])/double(speed[i]), position[i]};
        }

        sort(time_positional.begin(), time_positional.end(), [&](auto a, auto b){
            if(a.first != b.first) return a.first < b.first;
            else return a.second < b.second;
        });

        stack<pair<double,int>> stack;

        for(auto [time, position]: time_positional){
            while(not stack.empty() and stack.top().second < position){
                stack.pop();
            }
            stack.push({time, position});
        }

        return stack.size();
    }
};