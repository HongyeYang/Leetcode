int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left=1,right=n;
        while(left<=right){
            long mid=(left+right)/2;
            int res=guess(mid);
            if(res>0)left=mid+1;
            else if(res<0)right=mid-1;
            else return mid;
        }
        return left;
    }
};
