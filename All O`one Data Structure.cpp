class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!m.count(key)){
            if(buckets.empty()||buckets.back().val!=1){
                auto newBucket=buckets.insert(buckets.end(),{1,{key}});
                m[key]=newBucket;
            }
            else {
                auto minBucket=--buckets.end();
                minBucket->keys.insert(key);
                m[key]=minBucket;
            }
        }
        else{
            auto curBucket=m[key];
            auto lastBucket=(--m[key]);
            if(lastBucket==buckets.end()||lastBucket->val!=curBucket->val+1){
                auto newBucket=buckets.insert(curBucket,{curBucket->val+1,{key}});
                m[key]=newBucket;
            }
            else{
                lastBucket->keys.insert(key);
                m[key]=lastBucket;
            }
            curBucket->keys.erase(key);
            if(curBucket->keys.empty())buckets.erase(curBucket);
        }
        return;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!m.count(key))return;
        else{
            auto curBucket=m[key];
            if(curBucket->val==1)m.erase(key);
            else if(curBucket->val>1){
                auto nextBucket=(++m[key]);
                if(nextBucket==buckets.end()||nextBucket->val!=curBucket->val-1){
                    auto newBucket=buckets.insert(nextBucket,{curBucket->val-1,{key}});
                    m[key]=newBucket;
                }
                else{
                    nextBucket->keys.insert(key);
                    m[key]=nextBucket;
                }
            }
            curBucket->keys.erase(key);
            if(curBucket->keys.empty())buckets.erase(curBucket);
            
        }
        return;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(buckets.empty())return "";
        return *(buckets.begin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(buckets.empty())return "";
        return *(buckets.rbegin()->keys.begin());
    }
    
private:
    struct Bucket{int val;unordered_set<string>keys;};
    list<Bucket>buckets;
    unordered_map<string,list<Bucket>::iterator>m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
