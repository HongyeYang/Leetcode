class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        int count=0,repeat=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    count++;
                    if(i!=0&&grid[i-1][j]==1)repeat++;
                    if(j!=0&&grid[i][j-1]==1)repeat++;
                }
            }
        }
        return count*4-repeat*2;
    }
};
