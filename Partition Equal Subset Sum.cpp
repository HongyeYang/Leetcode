class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        bitset<5001>bits(1);
        for(int num:nums)bits|=bits<<num;
        return bits[sum>>1];
    }
};
