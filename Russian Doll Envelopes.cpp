class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.first<p2.first||(p1.first==p2.first&&p1.second>p2.second);
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size()==0)return 0;
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>dp;
        for(int i=0;i<envelopes.size();i++){
            int left=0,right=dp.size(),t=envelopes[i].second;
            while(left<right){
                int mid=(left+right)/2;
                if(dp[mid]<t)left=mid+1;
                else right=mid;
            }
            if(right>=dp.size())dp.push_back(t);
            else dp[right]=t;
        }
        return dp.size();
    }
};
