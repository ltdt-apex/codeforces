#include <bits/stdc++.h>
using namespace std;

class Twitter {
    private:
        unordered_map<int, unordered_set<int>> follows; // userid -> [set(followedid)]
        unordered_map<int, vector<pair<int,int>>> posts; // userid -> [{time,tweetid}]
        int t;
    public:
        Twitter() {
            t=0;
        }
        
        void postTweet(int userId, int tweetId) {
            posts[userId].push_back({t,tweetId});
            t++;
        }
        
        vector<int> getNewsFeed(int userId) {
            follows[userId].insert(userId);

            priority_queue<tuple<int,int,int>> q; // time, followeeid, index
            vector<int> ans;

            for(auto followee: follows[userId]){
                if(not posts[followee].empty()) {
                    auto [time, tid] = posts[followee].back();
                    int n = posts[followee].size();
                    q.push({time,followee,n-1});
                }
            }

            while(ans.size()<10 and not q.empty()){
                int time, fid, index;
                tie(time,fid,index) = q.top(); q.pop();

                ans.push_back(posts[fid][index].second);

                index--;
                if(index>=0){
                    auto [time, tid] = posts[fid][index];
                    q.push({time,fid,index});
                }
            }

            return ans;

        }
        
        void follow(int followerId, int followeeId) {
            follows[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            follows[followerId].erase(followeeId);
        }
    };

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */