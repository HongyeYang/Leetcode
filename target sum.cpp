class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum+S)%2||S>sum||S<(-sum))return 0;
        int target=(sum+S)/2;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};
