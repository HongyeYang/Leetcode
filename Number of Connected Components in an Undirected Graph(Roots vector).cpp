class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int>roots(n,0);
        for(int i=0;i<n;i++)roots[i]=i;
        int res=n;
        for(auto &p:edges){
            int id1=findRoot(roots,p.first);
            int id2=findRoot(roots,p.second);
            if(id1!=id2){
                res--;
                roots[id2]=id1;
            }
        }
        return res;
    }
    int findRoot(vector<int>&roots,int id){
        while(roots[id]!=id){
            roots[id]=roots[roots[id]];
            id=roots[id];
        }
        return id;
    }
};
