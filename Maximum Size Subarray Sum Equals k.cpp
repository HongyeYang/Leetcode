class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int>roc;
        roc[0]=-1;
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(roc.count(sum-k))res=max(res,i-roc[sum-k]);
            if(!roc.count(sum))roc[sum]=i;
        }
        return res;
    }
};
