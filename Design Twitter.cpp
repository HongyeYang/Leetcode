class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
       cnt=0; 
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId,userId);
        news[userId].insert({cnt++,tweetId});
        return;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        map<int,int>res;
        for(auto u=followers[userId].begin();u!=followers[userId].end();u++){
            int k=*u;
            for(auto a=news[k].begin();a!=news[k].end();a++){
                if(res.size()>0&&res.begin()->first>a->first&&res.size()>10)break;
                res.insert({a->first,a->second});
                if(res.size()>10)res.erase(res.begin());
            }
        }
        vector<int>r;
        for(auto a=res.rbegin();a!=res.rend();a++)r.push_back(a->second);
        return r;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        return;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)followers[followerId].erase(followeeId);
        return;
    }
private:
int cnt;
unordered_map<int,set<int>>followers;
unordered_map<int,map<int,int>>news;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
