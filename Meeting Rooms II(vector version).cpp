class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>starts;
        vector<int>ends;
        for(Interval &i:intervals){
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        
        int res=0,endptr=0;
        for(int i=0;i<starts.size();i++){
            if(starts[i]<ends[endptr])res++;
            else endptr++;
        }
        return res;
    }
};
