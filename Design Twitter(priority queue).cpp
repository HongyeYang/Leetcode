class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        friends[userId].insert(userId);
        tweets[userId].push_back({cnt++,tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>res;
        for(auto u=friends[userId].begin();u!=friends[userId].end();u++){
            for(int a=tweets[*u].size()-1;a>=0;a--){
                if(res.size()>0&&res.top().first>tweets[*u][a].first&&res.size()>=10)break;
                res.push(tweets[*u][a]);
                if(res.size()>10)res.pop();
            }
        }
        vector<int>r;
        while(!res.empty()){
            r.push_back(res.top().second);
            res.pop();
        }
        return vector<int>(r.rbegin(),r.rend());
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)friends[followerId].erase(followeeId);
    }
private:
int cnt=0;
unordered_map<int,unordered_set<int>>friends;
unordered_map<int,vector<pair<int,int>>>tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
