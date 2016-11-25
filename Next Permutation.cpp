class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return;
        int i=len-2,j=len-1;
        while(i>=0&&nums[i]>=nums[j]){
            i--;j--;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int k=len-1;
        while(nums[k]<=nums[i])k--;
        swap(nums[i],nums[k]);
        reverse(nums.begin()+j,nums.end());
        return;
    }
};
