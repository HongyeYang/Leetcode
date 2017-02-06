class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int cur=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)cur++;
            else{
                res=max(res,cur);
                cur=0;
            }
        }
        res=max(res,cur);
        return res;
    }
};
