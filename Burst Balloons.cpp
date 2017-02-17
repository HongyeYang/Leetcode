class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int len=1;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};
