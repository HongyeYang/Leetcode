class Solution {
public:
    void DST(vector<vector<int>>&res,vector<int>&cur,vector<int>&nums,int start){
        res.push_back(cur);
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1])continue;
            cur.push_back(nums[i]);
            DST(res,cur,nums,i+1);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>cur;
        if(!nums.size())return res;
        sort(nums.begin(),nums.end());
        DST(res,cur,nums,0);
        return res;
        
    }
};
