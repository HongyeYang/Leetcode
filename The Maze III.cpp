class Solution {
private:
struct point{
    int x;
    int y;
    int l;
    string path;
    point(int i,int j,int ll):x(i),y(j),l(ll),path(""){}
};
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m=maze.size();
        if(!m)return "impossible";
        int n=maze[0].size();
        if(!n)return "impossible";
        
        set<string>res;
        string dir="urdl";
        vector<int>dirs={-1,0,1,0,-1};
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[ball[0]][ball[1]]=0;
        point* start=new point(ball[0],ball[1],0);
        queue<point*>q;
        q.push(start);
        while(!q.empty()){
            point* p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nexti=p->x;
                int nextj=p->y;
                int len=p->l;
                string curp=p->path+dir[i];
                bool drop=false;
                while(nexti>=0&&nexti<m&&nextj>=0&&nextj<n&&maze[nexti][nextj]==0){
                    if(nexti==hole[0]&&nextj==hole[1]){
                        drop=true;
                        break;
                    }
                    nexti+=dirs[i];
                    nextj+=dirs[i+1];
                    len++;
                }
                if(drop){
                    if(len<dist[hole[0]][hole[1]]){
                        res.clear();
                        res.insert(curp);
                        dist[hole[0]][hole[1]]=len;
                    }
                    else if(len==dist[hole[0]][hole[1]])res.insert(curp);
                    continue;
                }
                nexti-=dirs[i];
                nextj-=dirs[i+1];
                len--;
                if(len==p->l)continue;
                if(len>dist[hole[0]][hole[1]])continue;
                if(len<=dist[nexti][nextj]){
                    dist[nexti][nextj]=len;
                    point* cc=new point(nexti,nextj,len);
                    cc->path=curp;
                    q.push(cc);
                }
                
            }
        }
        return res.empty()?"impossible":*res.begin();
    }
};
