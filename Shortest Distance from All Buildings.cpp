class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        int res=INT_MAX;
        vector<vector<int>>sum(m,vector<int>(n,0));
        int val=0;
        vector<int>dir{0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res=INT_MAX;
                    vector<vector<int>>dist=grid;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int ii=x+dir[k];
                            int jj=y+dir[k+1];
                            if(ii<0||ii>=m||jj<0||jj>=n||grid[ii][jj]!=val)continue;
                            grid[ii][jj]--;
                            dist[ii][jj]=dist[x][y]+1;
                            sum[ii][jj]+=(dist[ii][jj]-1);
                            res=min(res,sum[ii][jj]);
                            q.push({ii,jj});
                        }
                    }
                    val--;
                }
            }
        }
        
        return res==INT_MAX?-1:res;
    }
};
