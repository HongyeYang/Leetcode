class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if(!m)return;
        int n=rooms[0].size();
        if(!n)return;
        vector<vector<bool>>used(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==INT_MAX)rooms[i][j]=dfs(rooms,i,j);
            }
        }
        return;
    }
    int dfs(vector<vector<int>>&rooms,int i, int j){
        if(rooms[i][j]!=INT_MAX&&rooms[i][j]>=0)return rooms[i][j];
        int m=rooms.size(),n=rooms[0].size();
        int a=m*n;
        rooms[i][j]=-2;
        //up
        if(i>0&&rooms[i-1][j]>=0)a=min(a,dfs(rooms,i-1,j));
        
        //down
        if(i<m-1&&rooms[i+1][j]>=0)a=min(a,dfs(rooms,i+1,j));
        
        //left
        if(j>0&&rooms[i][j-1]>=0)a=min(a,dfs(rooms,i,j-1));
        //right
        if(j<n-1&&rooms[i][j+1]>=0)a=min(a,dfs(rooms,i,j+1));
        
        rooms[i][j]=INT_MAX;
        return a==m*n?INT_MAX:a+1;
    }
};
