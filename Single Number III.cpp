class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff=0;
        for(int n:nums)diff^=n;
        int mask=diff&(-diff);
        vector<int>res(2,0);
        for(int n:nums){
            if(n&mask){
                res[0]^=n;
            }
            else{
                res[1]^=n;
            }
        }
        return res;
    }
};
