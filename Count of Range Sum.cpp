class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long>sums{0};
        long long sum=0;
        int res=0;
        for(int n:nums){
            sum+=n;
            res+=distance(sums.lower_bound(sum-upper),sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return res;
    }
};
