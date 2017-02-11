class Solution {
public:
    bool isMatch(string s, string p) {
        int lens=s.size(),lenp=p.size();
        vector<vector<bool>>roc(lens+1,vector<bool>(lenp+1,false));
        roc[0][0]=true;
        
        for(int j=1;j<=lenp;j++){
            roc[0][j]=(roc[0][j-1]&&p[j-1]=='*');
        }
        
        for(int i=1;i<=lens;i++){
            for(int j=1;j<=lenp;j++){
                if(p[j-1]=='*')roc[i][j]=roc[i][j-1]||roc[i-1][j];
                else roc[i][j]=roc[i-1][j-1]&&(p[j-1]==s[i-1]||p[j-1]=='?');
            }
        }
        return roc[lens][lenp];
    }
};
