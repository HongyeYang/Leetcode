class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0;
        if(timeSeries.size()==0)return res;
        for(int i=1;i<timeSeries.size();i++){
            res+=min(duration,timeSeries[i]-timeSeries[i-1]);
        }
        res+=duration;
        return res;
    }
};
