class Solution {
public:
    int arrangeCoins(int n) {
        if(n<0)return n;
        long low = 1, high = n;
        while(low<=high){
            long mid= low + (high-low)/2;
            long tep=mid*(mid+1)/2;
            if(tep==n)return mid;
            else if(tep>n)high=mid-1;
            else low=mid+1;
        }
        return low-1;
    }
};
