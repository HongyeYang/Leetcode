class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,n=0;
        for(int c:nums)sum+=(-c+n++);
        return sum+n;
    }
};
