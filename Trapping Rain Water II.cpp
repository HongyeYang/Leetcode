class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size()==0||heightMap[0].size()==0)return 0;
        int m=heightMap.size(),n=heightMap[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        //visit the boundary
        //up and down
        for(int j=0;j<n;j++){
            pq.push({heightMap[0][j],j});
            visited[0][j]=true;
            
            pq.push({heightMap[m-1][j],(m-1)*n+j});
            visited[m-1][j]=true;
        }
       
        //left and right
        for(int i=1;i<m;i++){
            pq.push({heightMap[i][0],i*n});
            visited[i][0]=true;
            
            pq.push({heightMap[i][n-1],i*n+n-1});
            visited[i][n-1]=true;
        }
        
        //BFS
        int level=0;
        int res=0;
        while(!pq.empty()){
            pair<int,int>cur=pq.top();
            level=max(level,pq.top().first);
            int r=pq.top().second/n;
            int c=pq.top().second%n;
            pq.pop();
            //visit the unvisited neighbors
            //up
            if(r>0&&visited[r-1][c]==false)visit(heightMap,visited,r-1,c,level,n,res,pq);
            //down
            if(r<m-1&&visited[r+1][c]==false)visit(heightMap,visited,r+1,c,level,n,res,pq);
            //left
            if(c>0&&visited[r][c-1]==false)visit(heightMap,visited,r,c-1,level,n,res,pq);
            //right
            if(c<n-1&&visited[r][c+1]==false)visit(heightMap,visited,r,c+1,level,n,res,pq);
            
        }
        return res;
    }
    
    void visit(vector<vector<int>>&heightMap,vector<vector<bool>>&visited,int i,int j,int level,int& n,int&res,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq){
        res+=max(0,level-heightMap[i][j]);
        pq.push({heightMap[i][j],(i)*n+j});
        visited[i][j]=true;
        return;
    }
};
