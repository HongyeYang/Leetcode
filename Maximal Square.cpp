class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m)return 0;
        int n=matrix[0].size();
        if(!n)return 0;
        int res=0;
        vector<vector<int>>roc(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    roc[i+1][j+1]=min(min(roc[i][j],roc[i][j+1]),roc[i+1][j])+1;
                    res=max(res,roc[i+1][j+1]);
                }
            }
        }
        return res*res;
    }
};
