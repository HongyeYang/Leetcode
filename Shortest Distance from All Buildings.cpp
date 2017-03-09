class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        if(!m)return -1;
        int n=grid[0].size();
        if(!n)return -1;
        int res=INT_MAX;
        vector<int>dirs={-1,0,1,0,-1};
        vector<vector<int>>sum(m,vector<int>(n,0));
        int val=0;
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
                            int ni=x+dirs[k];
                            int nj=y+dirs[k+1];
                            if(ni<0||ni>=m||nj<0||nj>=n||grid[ni][nj]!=val)continue;
                            grid[ni][nj]--;
                            dist[ni][nj]=dist[x][y]+1;
                            sum[ni][nj]+=(dist[ni][nj]-1);
                            res=min(res,sum[ni][nj]);
                            q.push({ni,nj});
                        }
                        
                    }
                    if(res==INT_MAX)return -1;
                    val--;
                }
                
            }
        }
        return res==INT_MAX?-1:res;
    }
};
