class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>roc(n,0);
        for(int i=0;i<m;i++){
            if(!i)roc[0]=grid[0][0];
            else roc[0]=roc[0]+grid[i][0];
            for(int j=1;j<n;j++){
                if(!i)roc[j]=roc[j-1]+grid[i][j];
                else roc[j]=min(roc[j],roc[j-1])+grid[i][j];
            }
        }
        return roc.back();
    }
};
