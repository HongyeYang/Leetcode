class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target<1)return 0;
        vector<int>dp(target+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){
            for(int c:nums){
                if(c>i)break;
                dp[i]+=dp[i-c];
            }
        }
        return dp[target];
    }
};
