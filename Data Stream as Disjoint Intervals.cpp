/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        m.clear();
    }
    
    void addNum(int val) {
        auto it=m.lower_bound(Interval(val,val));
        int start=val,end=val;
        if(it!=m.begin()&&(--it)->end<val-1)it++;
        while(it!=m.end()&&it->start<=val+1){
            start=min(start,it->start);
            end=max(end,it->end);
            it=m.erase(it);
        }
        m.insert(Interval(start,end));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(m.begin(),m.end());
    }
    
private:
    struct cmp{
        bool operator()(Interval i1,Interval i2){
            return i1.start<i2.start;
        }
    };
    set<Interval,cmp>m;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
