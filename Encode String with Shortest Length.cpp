class Solution {
public:
    string encode(string s) {
        int len=s.size();
        vector<vector<string>>dp(len,vector<string>(len,""));
        for(int l=1;l<=len;l++){
            for(int i=0;i<=len-l;i++){
                int j=i+l-1;
                dp[i][j]=s.substr(i,l);
                for(int k=i;k<j;k++){
                    if((int)dp[i][k].size()+(int)dp[k+1][j].size()<(int)dp[i][j].size())dp[i][j]=dp[i][k]+dp[k+1][j];
                }
                
                string t=s.substr(i,l);
                int pos=(t+t).find(t,1);
                if(pos>=(int)t.size())continue;
                else{
                    string replace=to_string((int)t.size()/pos)+"["+dp[i][i+pos-1]+"]";
                    if((int)replace.size()<(int)dp[i][j].size())dp[i][j]=replace;
                }
            }
        }
        return dp[0][len-1];
    }
};
