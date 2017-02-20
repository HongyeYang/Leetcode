class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(right>left){
            int mid=left+(right-left)/2;
            if(nums[right]<nums[mid])left=mid+1;
            else if(nums[right]>nums[mid])right=mid;
            else right--;
        }
        return nums[left];
    }
};
