class Solution {
public:
    void BST(vector<vector<int>>&res,vector<int>&cur,vector<int>&nums,int start){
        int len=nums.size();
        res.push_back(cur);
        for(int i=start;i<len;i++){
            if(i>start&&nums[i]==nums[i-1])continue;
            cur.push_back(nums[i]);
            BST(res,cur,nums,i+1);
            cur.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        if(!nums.size())return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>cur;
        BST(res,cur,nums,0);
        return res;
    }
};
