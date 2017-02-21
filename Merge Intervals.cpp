class Solution {
public:
    static bool cmp(Interval i1,Interval i2){
        return i1.end<i2.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=intervals.size()-1;i>=1;i--){
            if(intervals[i].start<=intervals[i-1].end){
                intervals[i-1].end=intervals[i].end;
                intervals[i-1].start=min(intervals[i].start,intervals[i-1].start);
                intervals.erase(intervals.begin()+i);
            }
        }
        return intervals;
    }
};
