class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int>res;
        if(!m||!n)return res;
        vector<int>roots(m*n,-1);
        vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};
        int cnt=0;
        for(pair<int,int> &p:positions){
            int x=p.first,y=p.second;
            int id=x*n+y;
            roots[id]=id;
            cnt++;
            
            for(int k=0;k<4;k++){
                int i=x+dir[k][0],j=y+dir[k][1];
                int nid=i*n+j;
                if(i<0||i>=m||j<0||j>=n||roots[nid]==-1)continue;
                int rootn=findRoot(roots,nid);
                if(id!=rootn){
                    roots[id]=rootn;
                    id=rootn;
                    cnt--;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    int findRoot(vector<int>&roots, int id){
        while(roots[id]!=id){
            roots[id]=roots[roots[id]];
            id=roots[id];
        }
        return id;
    }
};
