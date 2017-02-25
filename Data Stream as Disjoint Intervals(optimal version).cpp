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
        Interval cur=Interval(val,val);
        auto it=m.lower_bound(Interval(val,val));
        if(it!=m.end()&&it->start==val)return;
        if(it!=m.begin()){
            it--;
            if(it->end>=val)return;
            if(it->end==val-1){
                cur.start=it->start;
                it=m.erase(it);
            }
            else it++;
        }
        if(it!=m.end()&&it->start==val+1){
            cur.end=it->end;
            m.erase(it);
        }
        m.insert(cur);
        return;
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

