class Solution {
public:
    bool isPowerOfFour(int num) {
        int test=1;
        for(int i=0;i<16;i++){
            if(num==test)return true;
            test<<=2;
        }
        return false;
    }
};
