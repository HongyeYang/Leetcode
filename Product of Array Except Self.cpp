class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        if(!len)return {};
        vector<int>res(len,1);
        int fwd=1,bwd=1;
        for(int i=0;i<len-1;i++){
            fwd*=nums[i];
            bwd*=nums[len-1-i];
            res[i+1]*=fwd;
            res[len-i-2]*=bwd;
        }
        return res;
    }
};
