class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)return x;
        double xpre=1,xpost=-1;
        while(abs(xpre-xpost)>=1){
            xpost=xpre;
            xpre=xpost/2+x/(2*xpost);
        }
        return xpre;
    }
};
