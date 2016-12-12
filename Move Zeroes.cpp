class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int i=0,j=0;
        for(;i<len;i++){
            if(nums[i])swap(nums[i],nums[j++]);
        }
        return;
    }
};
