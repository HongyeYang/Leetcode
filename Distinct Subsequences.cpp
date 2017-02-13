class Solution {
public:
    int numDistinct(string s, string t) {
        int lens=s.size(),lent=t.size();
        vector<vector<int>>dp(lens+1,vector<int>(lent+1,0));
        //init the dp matrix
        dp[0][0]=1;
        for(int i=1;i<=lens;i++)dp[i][0]=1;
        for(int j=1;j<=lent;j++)dp[0][j]=0;
        
        //complete the dp matrix
        for(int i=1;i<=lens;i++){
            for(int j=1;j<=lent;j++){
                dp[i][j]=dp[i-1][j]+(t[j-1]==s[i-1]?dp[i-1][j-1]:0);
            }
        }
        return dp[lens][lent];
    }
};
