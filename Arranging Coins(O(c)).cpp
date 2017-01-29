class Solution {
public:
    int arrangeCoins(int n) {
        return (-1+sqrt(1+(long)8*n))/2;
    }
};
