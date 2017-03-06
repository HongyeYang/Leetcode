class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        if(!m)return false;
        int n=maze[0].size();
        if(!n)return false;
        vector<vector<bool>>stoped(m,vector<bool>(n,false));
        return dfs(maze,stoped,start[0],start[1],{0,0},destination,m,n);
    }
    
    bool dfs(vector<vector<int>>&maze,vector<vector<bool>>&stoped,int i,int j,pair<int,int> d,vector<int>&des,int &m,int &n){
        //stop
        if((d.first==0&&d.second==0)||i+d.first<0||i+d.first>=m||j+d.second<0||j+d.second>=n||maze[i+d.first][j+d.second]==1){
            if(des[0]==i&&des[1]==j)return true;
            if(stoped[i][j])return false;
            stoped[i][j]=true;
            //up
            if(d.first!=1&&i>0&&maze[i-1][j]!=1){
                if(dfs(maze,stoped,i-1,j,{-1,0},des,m,n))return true;
            }
            //down
            if(d.first!=-1&&i<m-1&&maze[i+1][j]!=1){
                if(dfs(maze,stoped,i+1,j,{1,0},des,m,n))return true;
            }
            //left
            if(d.second!=1&&j>0&&maze[i][j-1]!=1){
                if(dfs(maze,stoped,i,j-1,{0,-1},des,m,n))return true;
            }
            //right
            if(d.second!=-1&&j<n-1&&maze[i][j+1]!=1){
                if(dfs(maze,stoped,i,j+1,{0,1},des,m,n))return true;
            }
            return false;
        }
        else return dfs(maze,stoped,i+d.first,j+d.second,d,des,m,n);
    }
};
