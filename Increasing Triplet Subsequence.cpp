class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        int smallest=INT_MAX,small=INT_MAX;
        for(int c:nums){
            if(c<=smallest)smallest=c;
            else if(c<=small)small=c;
            else return true;
        }
        return false;
    }
};
