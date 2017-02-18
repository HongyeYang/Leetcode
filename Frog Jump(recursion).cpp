class Solution {
public:
    bool dfs(vector<int>& stones,int pos,int jump,unordered_map<int,bool>&m){
        int n=stones.size(),key=pos|jump<<11;
        if(m.count(key))return m[key];
        if(pos>=n-1)return true;
        for(int i=pos+1;i<n;i++){
            int dist=stones[i]-stones[pos];
            if(dist<jump-1)continue;
            if(dist>jump+1)return m[key]=false;
            if(dfs(stones,i,dist,m))return m[key]=true;
        }
        return m[key]=false;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,bool>m;
        return dfs(stones,0,0,m);
    }
};
