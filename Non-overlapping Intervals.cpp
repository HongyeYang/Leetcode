class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.end<b.end;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size()==0)return 0;
        int res = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int last_end = INT_MIN;
        for(auto &c:intervals){
            if(c.start<last_end)res++;
            else last_end=c.end;
        }
        return res;
    }
};
