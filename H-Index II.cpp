class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len=citations.size();
        int left=0,right=len-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(citations[len-1-mid]>=mid+1)left=mid+1;
            else if(citations[len-mid]<mid)right=mid-1;
            else return mid;
        }
        return len;
    }
};
