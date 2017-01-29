/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,int>roc;
        vector<int>res;
        for(int i=0;i<intervals.size();i++){
            roc[intervals[i].start]=i;
        }
        for(int i=0;i<intervals.size();i++){
            auto it=roc.lower_bound(intervals[i].end);
            if(it==roc.end())res.push_back(-1);
            else res.push_back(it->second);
        }
        return res;
    }
};
