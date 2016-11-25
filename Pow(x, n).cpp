class Solution {
public:
    double myPow(double x, int n) {
        if(!x)return 0;
        if(x==1.0)return 1.0;
        if(n<0){
            if(n==INT_MIN)return 1/(myPow(x,INT_MAX)*x);
            else return 1/(myPow(x,-n));
        }
        double res=1;
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
};
