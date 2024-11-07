#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweetMap; // userid -> (time,tweetid)
    unordered_map<int, unordered_set<int>> followerMap; // follower id -> followee id
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int,int>> q;
        vector<int> tweets;

        followerMap[userId].insert(userId);

        for(auto followee: followerMap[userId]){
            int index = tweetMap[followee].size()-1;
            if(index<0) continue;
            auto [time, tweetid] = tweetMap[followee][index];
            q.push({time,index,tweetid,followee});
        }

        while(not q.empty() and tweets.size()<10){
            int time,index,tweetid,followee;
            tie(time,index,tweetid,followee) = q.top();

            q.pop();
            tweets.push_back(tweetid);

            index--;
            if(index<0) continue;

            auto [newtime, newtweetid] = tweetMap[followee][index];
            q.push({newtime,index,newtweetid,followee});
        }

        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
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