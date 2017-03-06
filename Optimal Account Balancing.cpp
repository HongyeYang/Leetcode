class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int>roc;
        //own others -, lend others +
        for(vector<int>&v:transactions){
            roc[v[0]]+=v[2];
            roc[v[1]]-=v[2];
        }
        vector<int>debt;
        for(auto p:roc){
            if(p.second)debt.push_back(p.second);
        }
        return dfs(0,0,debt);
    }
    
    int dfs(int s, int cnt,vector<int>&debt){
        int res=INT_MAX;
        while(s<debt.size()&&debt[s]==0)s++;
        int pre=0;
        for(int i=s+1;i<debt.size();i++){
            if(debt[i]==pre||debt[i]*debt[s]>0)continue;
            pre=debt[i];
            debt[i]+=debt[s];
            res=min(res,dfs(s+1,cnt+1,debt));
            debt[i]-=debt[s];
        }
        return res==INT_MAX?cnt:res;
    }
};
