class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //quick sort to find the median
        int k=nums.size()/2;
        nth_element(nums.begin(),nums.begin()+k,nums.end());
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=abs(nums[i]-nums[k]);
        }
        return res;
    }
};
