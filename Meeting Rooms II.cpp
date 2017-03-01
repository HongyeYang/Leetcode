class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int>roc;
        for(Interval &i:intervals){
            roc[i.start]++;
            roc[i.end]--;
        }
        int res=0;
        int rooms=0;
        auto it=roc.begin();
        for(;it!=roc.end();it++){
            rooms+=it->second;
            res=max(res,rooms);
        }
        return res;
    }
};
