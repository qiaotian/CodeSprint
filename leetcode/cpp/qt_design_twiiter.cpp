/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-11T09:18:14+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-11T20:23:44+08:00
* @Inc: Twitter
* @Difficulty: Medium
*/


// Notes: OOD questions often intentionally vague to test if you 'll make assumptions, or if you'll ask clarigying questions. How do you design a class if the constraints are vague? Ask questions to eliminate ambiguity, then design the classes to handle any remaining ambiguity.

//

/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 注意小根堆定义lamda表达式时使用大于号

class Twitter {
public:
    int time = 0;
    typedef struct Tweet {
        int time;
        int id;
        Tweet(int time, int id): time(time), id(id) {}
    } Tweet;

    /** Initialize your data structure here. */
    unordered_map<int, vector<Tweet>> tweets; // map user to his or her own tweets(followees' not inluded)
    unordered_map<int, unordered_set<int>> followees; // map user to his or her followees
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet t = Tweet(time++, tweetId);
        tweets[userId].push_back(t);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        // 定义小根堆
        // Using lambda to compare elements.
        // auto cmp = [](int left, int right) { return left > right;};
        // std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        auto cmp = [](Tweet& a, Tweet& b) {return a.time > b.time;};
        std::priority_queue<Tweet, vector<Tweet>, decltype(cmp)> pq(cmp);

        // 定义大根堆（默认）
        // priority_queue<int> pq;
        unordered_set<int> f = followees[userId]; // 某用户关注的所有人
        f.insert(userId);
        for(auto i:f) {
            vector<Tweet> _tweets = tweets[i]; // 被关注的某人发布的所有推特
            for(auto j:_tweets) {
                if(pq.size()<10) {
                    pq.push(j);
                } else {
                    if(j.time > pq.top().time) {pq.pop(); pq.push(j);}
                    else continue;
                }
            }
        }
        f.erase(userId);
        int n = pq.size();
        ans.resize(n);
        for(int i=0; i<n; i++) {
            ans[n-1-i] = pq.top().id;
            pq.pop();
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
int main() {
    Twitter obj = Twitter();
    obj.postTweet(1, 10);
    vector<int> param_2 = obj.getNewsFeed(1);
    obj.follow(2, 1);
    obj.unfollow(2, 1);

    return 0;
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
