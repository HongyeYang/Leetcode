class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        int res=0;
        for(int i=0;i<32;i++){
            int ones=0;
            for(int num:nums){
                if(num&(1<<i))ones++;
            }
            res+=(ones*(n-ones));
        }
        return res;
    }
};
