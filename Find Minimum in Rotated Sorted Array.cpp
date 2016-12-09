class Solution {
public:
    int findMin(vector<int>& nums) {
        int len=nums.size();
        for(int i=1;i<len;i++){
            if(nums[i]<nums[i-1])return nums[i];
        }
        return nums[0];
    }
};
