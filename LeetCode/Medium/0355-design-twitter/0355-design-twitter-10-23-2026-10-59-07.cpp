class Twitter {
public:
    int timeStamp = 0;

    // userId -> list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> user_tweets;

    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> user_follows;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        // Add the user's own tweets
        for (auto tweet : user_tweets[userId]) {
            maxHeap.push(tweet);
        }

        // Add tweets from followed users
        for (int followeeId : user_follows[userId]) {
            for (auto tweet : user_tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        vector<int> feed;

        // Return at most 10 most recent tweets
        while (!maxHeap.empty() && feed.size() < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            user_follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        user_follows[followerId].erase(followeeId);
    }
};
