class Solution {
public:
    int countArrangement(int N) {
        vector<int>nums;
        for(int i=1;i<=N;i++)nums.push_back(i);
        return dfs(N,nums);
    }
    int dfs(int n,vector<int>&nums){
        if(n<=0)return 1;
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]%n==0||n%nums[i]==0){
                swap(nums[n-1],nums[i]);
                res+=dfs(n-1,nums);
                swap(nums[n-1],nums[i]);
            }
        }
        return res;
    }
};
