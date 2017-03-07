class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int lenr=ring.size(),lenk=key.size();
        unordered_map<char,vector<int>>roc;
        vector<int>dp(lenr,0);
        
        for(int i=0;i<lenr;i++){
            roc[ring[i]].push_back(i);
        }
        int res=INT_MAX;
        vector<int>last={0};
        //dp traversal
        for(int i=1;i<=lenk;i++){
            for(auto it:roc[key[i-1]]){
                int mindist=INT_MAX;
                for(int j=0;j<last.size();j++){
                    int dist=min((it+lenr-last[j])%lenr,(last[j]+lenr-it)%lenr)+dp[last[j]];
                    mindist=min(mindist,dist);
                }
                dp[it]=mindist;
                if(i==lenk)res=min(res,dp[it]);
            }
            last=roc[key[i-1]];
        }
        return res+lenk;
    }
};
