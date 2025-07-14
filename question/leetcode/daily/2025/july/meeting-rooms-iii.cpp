#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        priority_queue<int, vector<int>, greater<int>> unused;
        for(int i=0;i<n;i++){
            unused.push(i);
        }

        int count = 0;
        long long leastAvailableTime = 0;
        vector<int> nUsed(n);

        for(int i=0;i<m;i++){
            while(not q.empty() and q.top().first<=meetings[i][0]){
                auto [prevEnd, prevIndex] = q.top(); q.pop();
                count--;
                unused.push(prevIndex);
            }

            if(count==n) {
                auto [prevEnd, prevIndex] = q.top(); q.pop();
                count--;
                unused.push(prevIndex);
                leastAvailableTime = prevEnd;
            }
            
            int room = unused.top(); unused.pop();
            long long end = meetings[i][1];
            if(leastAvailableTime > meetings[i][0]){
                end+=leastAvailableTime-meetings[i][0];
            }

            // cout << room << " " << leastAvailableTime << " " << end << endl;
            q.push({end,room});
            nUsed[room]++;
            count++;
        }

        int maxRoom = 0;

        for(int room=0;room<n;room++){
            if(nUsed[room]>nUsed[maxRoom]) maxRoom = room;
        }

        return maxRoom;
    }
};