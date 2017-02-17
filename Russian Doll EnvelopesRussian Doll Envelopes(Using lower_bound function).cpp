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
            int t=envelopes[i].second;
            auto it=lower_bound(dp.begin(),dp.end(),t);
            if(it==dp.end())dp.push_back(t);
            else (*it=t);
        }
        return dp.size();
    }
};
