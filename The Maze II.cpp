class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        if(!m)return -1;
        int n=maze[0].size();
        if(!n)return -1;
        
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        q.push({start[0]*n+start[1],0});
        //dist[start[0]][start[1]]=0;
        vector<int>dir={-1,0,1,0,-1};
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nexti=p.first/n;
                int nextj=p.first%n;
                int l=p.second;
                while(nexti>=0&&nexti<m&&nextj>=0&&nextj<n&&maze[nexti][nextj]==0){
                    nexti+=dir[i];
                    nextj+=dir[i+1];
                    l++;
                }
                nexti-=dir[i];
                nextj-=dir[i+1];
                l--;
                if(dist[destination[0]][destination[1]]<l)continue;
                if(dist[nexti][nextj]>l){
                    dist[nexti][nextj]=l;
                    q.push({nexti*n+nextj,l});
                }
            }
        }

        return dist[destination[0]][destination[1]]==INT_MAX?-1:dist[destination[0]][destination[1]];
    }
};
