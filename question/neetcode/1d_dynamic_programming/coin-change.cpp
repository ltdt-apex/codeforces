#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount+1, INT_MAX);
        count[0] = 0;

        for(auto c: coins){
            for(int i=1;i<=amount;i++){
                // cout << i << " " << count[i] << endl;
                if(i-c<0 or count[i-c] == INT_MAX) continue;
                count[i] = min(count[i], count[i-c]+1);

            }
        }

        if(count[amount] == INT_MAX) return -1;
        return count[amount];
    }
};