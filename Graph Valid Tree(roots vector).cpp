class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int>roots(n,0);
        for(int i=0;i<n;i++)roots[i]=i;
        
        for(pair<int,int>&e:edges){
            int f=e.first;
            int s=e.second;
            while(roots[f]!=f)f=roots[f];
            while(roots[s]!=s)s=roots[s];
            if(f==s)return false;
            roots[s]=f;
        }
        return (int)edges.size()==n-1;
    }
};
