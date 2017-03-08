class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //deal with the corner cases
        int m=rooms.size();
        if(!m)return ;
        int n=rooms[0].size();
        if(!n)return;
        
        vector<int>dirs={-1,0,1,0,-1};
        //traver the matrix and find the gate as the starting point of dfs
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0)dfs(rooms,i,j,0,m,n,dirs);
            }
        }
        return;
        
    }
    
    void dfs(vector<vector<int>>&rooms,int i,int j,int cnt,int &m, int &n,vector<int>&dirs){
        rooms[i][j]=cnt;
        for(int k=0;k<4;k++){
            int ni=i+dirs[k];
            int nj=j+dirs[k+1];
            if(ni>=0&&ni<m&&nj>=0&&nj<n&&rooms[ni][nj]>cnt+1)dfs(rooms,ni,nj,cnt+1,m,n,dirs);
        }
        return;
    }
};
