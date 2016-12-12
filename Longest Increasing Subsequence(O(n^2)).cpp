class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        vector<int>roc(len,1);
        int res=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])roc[i]=max(roc[i],roc[j]+1);
            }
            res=max(res,roc[i]);
        }
        return res;
    }
};
