class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(!len)return 0;
        int res=1;
        for(int i=1;i<len;i++){
           if(nums[i]!=nums[i-1])nums[res++]=nums[i];
        }
        return res;
    }
};
