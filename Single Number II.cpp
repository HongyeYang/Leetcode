class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size();
        int res=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<len;j++){
                sum+=(nums[j]>>i)&1;
            }
            res+=(sum%3)<<i;
        }
        return res;
    }
};
