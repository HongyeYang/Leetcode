class Solution {
public:
    int reverse(int x) {
        long long res=0;
        int sign=1;
        if(!x||x==-2147483648)return 0;
        if(x<0){
            x=-x;
            sign=-1;
        }
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        if(res>INT_MAX)return 0;
        return sign<0?-res:res;
    }
};
