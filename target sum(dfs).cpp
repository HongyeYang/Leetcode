class Solution {
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    void dfs(vector<int>&nums,int target,int start,int &res){
        if(target==0)res++;
        if(start>=nums.size()||target<0)return;
        else{
            for(int i=start;i<nums.size();i++){
                dfs(nums,target-nums[i],i+1,res);
            }
        }
        return;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<S||S<(-sum)||(sum+S)%2)return 0;
        int target=(sum+S)/2;
        int res=0;
        sort(nums.begin(),nums.end(),cmp);
        dfs(nums,target,0,res);
        return res;
    }
};
