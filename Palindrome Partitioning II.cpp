class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>isP(n,vector<bool>(n,false));
        vector<int>dp(n+1,n);
        dp[n]=-1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<=1||isP[i+1][j-1])){
                    isP[i][j]=true;
                    dp[i]=min(dp[i],dp[j+1]+1);
                }
            }
        }
        return dp[0];
    }
};
