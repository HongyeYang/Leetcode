class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor)return INT_MAX;
        if(!dividend)return 0;
        if(divisor==1)return dividend;
        if(dividend==divisor)return 1;
        int sign=1;
        long long dig=1;
        long long res=0;
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0))sign=-1;
        long long dd=abs((long)dividend),dv=abs((long)divisor);
        if(dd<dv)return 0;
        
        while(dd>dv){
            dv<<=1;
            dig<<=1;
        }
        while(dd>=abs(divisor)){
            while(dd<dv){
                dv>>=1;
                dig>>=1;
            }
            res+=dig;
            dd-=dv;
            if(res>INT_MAX)return INT_MAX;
        }
        return sign==1?res:-res;
    }
};
