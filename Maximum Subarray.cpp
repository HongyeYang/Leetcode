class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0],cur=0,i=0;
        while(nums[i]<0){
            res=max(res,nums[i]);
            i++;
        }
        for(;i<nums.size();i++){
            cur+=nums[i];
            cur=max(cur,0);
            res=max(res,cur);
        }
        return res;
    }
};
