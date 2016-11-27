class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;dp[1]=1;dp[2]=2;
        for(int cur=3;cur<=n;cur++){
            int rr=0;
            for(int i=0;i<=cur-1;i++)rr=rr+dp[i]*dp[cur-1-i];
            dp[cur]=rr;
        }
        return dp.back();
    }
};
