class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z<=x+y&&(z==0||!(z%gcd(x,y)));
    }
    int gcd(int x,int y){
        return !y?x:gcd(y,x%y);
    }
};
