class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        res=0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(!roc.empty()&&roc.back().first==timestamp){
            roc.back().second++;
        }
        else{
            roc.push_back({timestamp,1});
        }
        res++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!roc.empty()&&(timestamp-roc.front().first)>=300){
            res-=roc.front().second;
            roc.pop_front();
        }
        return res;
    }
    
private:
int res=0;
list<pair<int,int>>roc;
};

