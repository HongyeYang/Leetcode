class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0,pre=-1,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])cur++;
            else{
                res=max(res,cur+1+pre);
                pre=cur;
                cur=0;
            }
        }
        res=max(res,cur+1+pre);
        return res;
    }
};
