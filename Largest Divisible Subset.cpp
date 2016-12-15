class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len=nums.size();
        if(!len)return {};
        vector<int>res;
        vector<int>dp(len,1);
        vector<int>parent(len,-1);
        sort(nums.begin(),nums.end());
        int maxid=0,maxlen=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                    if(dp[i]>maxlen){
                        maxlen=dp[i];
                        maxid=i;
                    }
                }
            }
        }
        while(maxid>-1){
            res.push_back(nums[maxid]);
            maxid=parent[maxid];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
