#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int a = startTime[0];

        int freeTime = startTime[0];
        int n = startTime.size();

        for(int right=1;right<n+1;right++){
            if (right==n) freeTime+=eventTime-endTime[n-1];
            else freeTime+=startTime[right]-endTime[right-1];

            if(right>=k){
                a = max(a,freeTime);
                int left = right-k;
                
                if(left==0) freeTime-=startTime[0];
                else freeTime-=startTime[left]-endTime[left-1];
            }
        }

        return a;
    }
};