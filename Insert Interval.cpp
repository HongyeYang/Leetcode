class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int s=0,e=intervals.size()-1;
        if(intervals.size()==0)return {newInterval};
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].end<newInterval.start)s=i+1;
            if(intervals[i].start>newInterval.end){
                e=i-1;
                break;
            }
        }
        if(s<intervals.size())newInterval.start=min(intervals[s].start,newInterval.start);
        if(e>=0&&e<intervals.size())newInterval.end=max(intervals[e].end,newInterval.end);
        if(s>e)intervals.insert(intervals.begin()+s,newInterval);
        else{
            intervals[s]=newInterval;
            int j=s+1;
            for(int i=e+1;i<intervals.size();i++){
                swap(intervals[j++],intervals[i]);
            }
            for(int i=s+1;i<=e;i++)intervals.pop_back();
        }
        
        return intervals;
    }
};
