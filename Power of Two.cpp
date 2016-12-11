class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)return false;
        int res=0;
        for(int i=0;i<31;i++)res+=(n>>i)&1;
        return res==1;
    }
};
