class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if(!m)return;
        int n=rooms[0].size();
        if(!n)return;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0){
                    dfs(rooms,i,j,0);
                }
            }
        }
        return;
    }
    void dfs(vector<vector<int>>&rooms,int i,int j,int val){
        rooms[i][j]=val;
        int m=rooms.size(),n=rooms[0].size();
        //up
        if(i>0&&rooms[i-1][j]>val+1)dfs(rooms,i-1,j,val+1);
        //down
        if(i<m-1&&rooms[i+1][j]>val+1)dfs(rooms,i+1,j,val+1);
        //left
        if(j>0&&rooms[i][j-1]>val+1)dfs(rooms,i,j-1,val+1);
        //right
        if(j<n-1&&rooms[i][j+1]>val+1)dfs(rooms,i,j+1,val+1);
        return;
    }
};
