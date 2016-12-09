class Solution {
public:
    void plat(vector<vector<char>>&grid,int i,int j){
        grid[i][j]='0';
        if(i>0&&grid[i-1][j]=='1')plat(grid,i-1,j);
        if(i<grid.size()-1&&grid[i+1][j]=='1')plat(grid,i+1,j);
        if(j>0&&grid[i][j-1]=='1')plat(grid,i,j-1);
        if(j<grid[0].size()-1&&grid[i][j+1]=='1')plat(grid,i,j+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    plat(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
