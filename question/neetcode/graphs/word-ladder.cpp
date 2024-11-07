#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isDifferByOneWord(string x, string y){
        int n = x.size();
        int count = 0;

        for(int i=0;i<n;i++){
            if(x[i]!=y[i]) count++;
        }

        return count==1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();

        vector<vector<int>> adj(n);

        int endWordIndex = -1;

        for(int i=0;i<n;i++){
            if(wordList[i] == endWord) endWordIndex = i;
            for(int j=0;j<i;j++){
                if(isDifferByOneWord(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if(endWordIndex==-1) return 0;

        queue<pair<int,int>> q;
        vector<int> seen(n);
        seen[n-1] = 1;
        q.push({n-1,1});

        while(not q.empty()){
            auto [u,d] = q.front();
            q.pop();

            if(u==endWordIndex) return d;

            for(auto v: adj[u]){
                if(seen[v]) continue;
                seen[v]=1;
                q.push({v,d+1});
            }
        }

        return 0;
    }
};