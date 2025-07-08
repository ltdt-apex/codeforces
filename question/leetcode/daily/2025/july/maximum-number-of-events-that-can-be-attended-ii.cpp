#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        sort(events.begin(), events.end());

        vector<vector<long long>> scores(k+1, vector<long long>(n+1, 0));

        for(int i=0;i<n;i++){
            if(i>0){
                for(int j=0;j<k+1;j++){
                    scores[j][i] = max(scores[j][i], scores[j][i-1]);
                }
            }
            
            vector<int> ne = {events[i][1]+1,0,0};
            
            auto it = lower_bound(events.begin(), events.end(), ne);
            
            int ni = 0;
            if(it==events.end()){
                ni = n;
            }
            else{
                ni = it - events.begin();
            }
            
            // cout << events[i][0] << ' ' << events[i][1] << " " << events[i][2] << " " << ni << endl;
            // cout << ni << endl;

            for(int j=1;j<k+1;j++){
                scores[j][ni] = max(scores[j][ni], scores[j-1][i]+events[i][2]);
            }
        }

        int a = 0;


        for(int j=0;j<k+1;j++){
            scores[j][n] = max(scores[j][n], scores[j][n-1]);
            a = max(a, (int)scores[j][n]);
        }

        return a;
    }
};