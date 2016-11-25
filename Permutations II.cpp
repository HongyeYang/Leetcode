class Solution {
public:
    void BST(vector<int>& nums,vector<int>&cur,vector<bool>&roc,int k,vector<vector<int>>&res){
        if(!k){
            res.push_back(cur);
            return;
        }
        int len=nums.size();
        for(int i=0;i<len;i++){
            if((!roc[i])||(i>0&&nums[i]==nums[i-1]&&roc[i-1])){
                continue;
            }
            if(roc[i]){
                cur.push_back(nums[i]);
                roc[i]=false;
                BST(nums,cur,roc,k-1,res);
                cur.pop_back();
                roc[i]=true;
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len=nums.size();
        if(!len)return {};
        vector<vector<int>>res;
        vector<int>cur;
        vector<bool>roc(len,true);
        sort(nums.begin(),nums.end());
        BST(nums,cur,roc,len,res);
        return res;
    }
};
