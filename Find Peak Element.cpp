class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len=nums.size();
        int left=0,right=len-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if((mid==0||(nums[mid]>nums[mid-1]))&&(mid==len-1||(nums[mid]>nums[mid+1])))return mid;
            if(nums[mid]<nums[mid+1])left=mid+1;
            else right=mid-1;
        }
        return mid;
    }
};
