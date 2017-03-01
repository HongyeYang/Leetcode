class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if(n<4)return {};
        vector<vector<int>>res;
        vector<int> cur;
        dfs(n,2,cur,res);
        return res;
    }
    
    void dfs(int n, int bottom, vector<int>&cur, vector<vector<int>>&res){
        int end=sqrt(n);
        for(int i=bottom;i<=end;i++){
            if(n%i)continue;
            int d=n/i;
            cur.push_back(i);
            dfs(d,i,cur,res);
            cur.push_back(d);
            res.push_back(cur);
            cur.pop_back();
            cur.pop_back();
        }
        return;
    }
};
