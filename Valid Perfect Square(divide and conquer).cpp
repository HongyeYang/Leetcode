class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;
        int left=0,right=num/2;
        while(left<=right){
            long mid=(left+right)/2;
            if(num>mid*mid)left=mid+1;
            else if(num<mid*mid)right=mid-1;
            else return true;
        }
        return false;
    }
};
