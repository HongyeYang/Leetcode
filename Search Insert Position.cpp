class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        if(!len)return 0;
        if(target>nums[len-1])return len;
        int left=0,right=len-1,mid=left;
        while(left<=right){
            mid=(left+right)/2;
            if(target>nums[mid])left=mid+1;
            else if(target<nums[mid])right=mid-1;
            else return mid;
        }
        return target>nums[mid]?mid+1:mid;
    }
};
