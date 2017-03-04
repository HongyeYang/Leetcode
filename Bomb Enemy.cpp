class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        vector<vector<int>>rows(m,vector<int>(n,0));
        vector<vector<int>>cols(m,vector<int>(n,0));
        
        //building rows
        for(int i=0;i<m;i++){
            int left=0;
            int cnt=0;
            for(int j=0;j<=n;j++){
                if(j==n||grid[i][j]=='W'){
                    for(int k=left;k<j;k++)rows[i][k]=cnt;
                    cnt=0;
                    left=j+1;
                }
                else if(grid[i][j]=='E')cnt++;
            }
        }
        
        //building cols
        for(int j=0;j<n;j++){
            int up=0;
            int cnt=0;
            for(int i=0;i<=m;i++){
                if(i==m||grid[i][j]=='W'){
                    for(int k=up;k<i;k++)cols[k][j]=cnt;
                    cnt=0;
                    up=i+1;
                }
                else if(grid[i][j]=='E')cnt++;
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0')res=max(res,rows[i][j]+cols[i][j]);
            }
        }
        return res;
    }
};
