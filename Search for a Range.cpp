class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int>res={-1,-1};
        if(!len)return res;
        int left=0,right=len-1,mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]<target)left=mid+1;
            else if(nums[mid]>target)right=mid-1;
            else break;
        }
        if(nums[mid]!=target)return res;
        int i=mid,j=mid;
        while(i>0&&nums[i-1]==target)i--;
        while(j<len-1&&nums[j+1]==target)j++;
        return {i,j};
    }
};
