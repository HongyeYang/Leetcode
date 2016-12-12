bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left=1,right=n,mid;
        while(left<=right){
            mid=(left+right)/2;
            bool cur=isBadVersion(mid);
            if(!cur)left=mid+1;
            else if(mid>0&&isBadVersion(mid-1))right=mid-1;
            else return mid;
        }
        return left;
    }
};
