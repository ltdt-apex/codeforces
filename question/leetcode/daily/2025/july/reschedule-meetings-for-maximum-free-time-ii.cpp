#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({startTime[0], 0});
        q.push({eventTime-endTime.back(), endTime.back()});

        for(int i=1;i<n;i++){
            q.push({startTime[i]-endTime[i-1],endTime[i-1]});
            if(q.size()>3) q.pop();
        }

        vector<pair<int,int>> top3;
        while(not q.empty()){
            top3.push_back(q.top()); q.pop();
        }

        int a = startTime[0];
        int lastFree = startTime[0];
        for(int i=0;i<n;i++){
            int curFree;
            if(i==n-1) curFree = eventTime - endTime[i];
            else curFree = startTime[i+1]-endTime[i];
            int curboxD = endTime[i]-startTime[i];

            int left = startTime[i]-lastFree;
            int right = endTime[i]+curFree;

            // cout << lastFree << " " << curFree << endl;

            for(int j=0;j<top3.size();j++){
                int d = top3[j].first;
                int start = top3[j].second;
                int end = start+d;

                if(d<curboxD or (left<=start and right>=end)) continue;
                // cout << start << " " << end << endl;
                
                a = max(a, curFree+lastFree+curboxD);
            }

            a = max(a,curFree+lastFree);

            lastFree = curFree;
        }

        return a;
    }
};