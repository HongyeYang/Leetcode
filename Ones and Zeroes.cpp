class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zeros=0,ones=0;
        vector<vector<int>>roc(m+1,vector<int>(n+1,0));
        for(int k=0;k<strs.size();k++){
            zeros=0;
            ones=0;
            for(char c:strs[k]){
                if(c=='0')zeros++;
                else ones++;
            }
            
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    roc[i][j]=max(roc[i-zeros][j-ones]+1,roc[i][j]);
                }
            }
        }
        return roc[m][n];
    }
};
