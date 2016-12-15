class Solution {
public:
    int getMoneyAmount(int n) {
        if(n<2)return n-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>0;j--){
                int gm=INT_MAX;
                for(int k=j+1;k<i;k++){
                    gm=min(gm,max(dp[k+1][i],dp[j][k-1])+k);
                }
                dp[j][i]=j==i-1?j:gm;
            }
        }
        return dp[1][n];
    }
};
