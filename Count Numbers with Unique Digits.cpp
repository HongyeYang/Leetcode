class Solution {
public:
    int step(int dig){
        int res=9,tt=9;
        while(--dig){
            res*=tt;
            tt--;
        }
        return res;
    }
    int countNumbersWithUniqueDigits(int n) {
        int res=1,k=1;
        while(k<=n){
            res=res+step(k++);
        }
        return res;
    }
};
