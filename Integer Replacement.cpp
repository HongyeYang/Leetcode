class Solution {
public:
    int integerReplacement(int n) {
        if(n==1)return 0;
        if(n%2)return min(integerReplacement(n/2),integerReplacement(n/2+1))+2;
        else return integerReplacement(n/2)+1;
    }
};
