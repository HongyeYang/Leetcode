class Solution {
public:
    bool recur(vector<int>& nums, int start, int end, int s1, int s2){
        if(end-start<2&&((s2-s1)<=abs(nums[start]-nums[end])))return true;
        return !(recur(nums,start+1,end,s2,s1+nums[start])&&recur(nums,start,end-1,s2,s1+nums[end]));
    }
    bool PredictTheWinner(vector<int>& nums) {
        return recur(nums,0,nums.size()-1,0,0);
    }
};
