class Solution {
public:
    void DST(vector<int>& candidates,vector<int>&cur,int target,int start,vector<vector<int>>&res){
        if(!target)res.push_back(cur);
        if(target<0)return;
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1])continue;
            cur.push_back(candidates[i]);
            DST(candidates,cur,target-candidates[i],i+1,res);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(!candidates.size())return {};
        vector<vector<int>>res;
        vector<int>cur;
        sort(candidates.begin(),candidates.end());
        DST(candidates,cur,target,0,res);
        return res;
    }
};

