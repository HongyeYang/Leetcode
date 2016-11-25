class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        if(!len)return 0;
        int i=0, j=len-1;
        while(j>=0&&nums[j]==val)j--;
        while(i<=j){
            if(nums[i]!=val)i++;
            else{
                swap(nums[i],nums[j]);
                while(nums[j]==val)j--;
                if(j<0)return 0;
                i++;
            }
        }
        return i;
    }
};
