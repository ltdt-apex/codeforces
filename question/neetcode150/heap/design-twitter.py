from collections import defaultdict
from typing import List

class Twitter:

    def __init__(self):
        self.followed = defaultdict(set)
        self.posted = defaultdict(list)
        self.t = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posted[userId].append((tweetId, self.t))
        self.t+=1

    def getNewsFeed(self, userId: int) -> List[int]:
        ans = []

        self.followed[userId].add(userId)
        indexs = [len(self.posted[user])-1 for user in self.followed[userId]]

        for _ in range(10):
            mt = -1
            mid = -1
            mi = -1
            for i, user in enumerate(self.followed[userId]):
                if indexs[i] == -1:
                    continue
                tweet_id, t = self.posted[user][indexs[i]]
                if t > mt:
                    mt = t
                    mid = tweet_id
                    mi = i

            indexs[mi]-=1
            if mid == -1:
                break
            ans.append(mid)

        return ans

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followed[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followed[followerId]:
            self.followed[followerId].remove(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)