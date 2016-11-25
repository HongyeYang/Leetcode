class Solution {
public:
    void BST(vector<int>&cur,vector<bool>&roc,int k,vector<int>&nums,vector<vector<int>>&res){
        if(!k){
            res.push_back(cur);
            return;
        }
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(roc[i]){
                cur.push_back(nums[i]);
                roc[i]=false;
                BST(cur,roc,k-1,nums,res);
                cur.pop_back();
                roc[i]=true;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        if(!len)return {};
        vector<vector<int>>res;
        vector<bool>roc(len,true);
        vector<int>cur;
        BST(cur,roc,len,nums,res);
        return res;
    }
};
