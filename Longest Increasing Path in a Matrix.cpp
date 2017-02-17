class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& roc,int i, int j,int pre){
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())return 0;
        if(matrix[i][j]<=pre)return 0;
        if(roc[i][j]!=0)return roc[i][j];
        //up
        int a=dfs(matrix,roc,i-1,j,matrix[i][j])+1;
        //down
        int b=dfs(matrix,roc,i+1,j,matrix[i][j])+1;
        //left
        int c=dfs(matrix,roc,i,j-1,matrix[i][j])+1;
        //right
        int d=dfs(matrix,roc,i,j+1,matrix[i][j])+1;
        
        roc[i][j]=max(a,max(b,max(c,d)));
        
        return roc[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m)return 0;
        int n=matrix[0].size();
        if(!n)return 0;
        vector<vector<int>>roc(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,dfs(matrix,roc,i,j,INT_MIN));
            }
        }
        return res;
    }
};
