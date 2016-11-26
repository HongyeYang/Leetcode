class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int>roc(n,1);
        if(obstacleGrid[0][0]==1)return 0;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1)roc[0]=0;
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)roc[j]=0;
                else{
                if(i==0)roc[j]=roc[j-1];    
                else roc[j]=roc[j]+roc[j-1];
                }
            }
        }
        return roc.back();
    }
};
