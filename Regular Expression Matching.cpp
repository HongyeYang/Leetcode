class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())return s.empty();
        int m=s.size(),n=p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        //init dp matrix
        dp[0][0]=true;
        for(int i=1;i<=m;i++)dp[i][0]=false;
        for(int j=1;j<=n;j++)dp[0][j]=p[j-1]=='*'&&dp[0][j-2];
        
        //fill our dp matrix
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*')dp[i][j]=dp[i-1][j-1]&&(p[j-1]==s[i-1]||p[j-1]=='.');
                else{
                    dp[i][j]=dp[i][j-2]||(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
