class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len=nums.size();
        int minnum=nums[0],maxnum=nums[0];
        int res=nums[0];
        for(int i=1;i<len;i++){
            int premin=minnum;
            minnum=min(min(minnum*nums[i],nums[i]),maxnum*nums[i]);
            maxnum=max(max(maxnum*nums[i],nums[i]),premin*nums[i]);
            res=max(res,maxnum);
        }
        return res;
    }
};
