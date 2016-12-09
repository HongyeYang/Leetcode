class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d=0;
        while(1){
            if(m==n)break;
            m>>=1;
            n>>=1;
            d++;
            
        }
        return m<<d;
    }
};
