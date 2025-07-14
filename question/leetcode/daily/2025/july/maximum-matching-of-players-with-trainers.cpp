#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int a = 0;
        int j = 0;
        for(int i=0;i<players.size();i++){
            while(j<trainers.size() and players[i]>trainers[j]) j++;
            if(j<trainers.size() and players[i]<=trainers[j]){
                a++;
                j++;
            }
        }

        return a;
    }
};