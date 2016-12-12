class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>roc;
        roc.push_back(1);
        int i=2,j=3,k=5,ith=0,jth=0,kth=0;
        while(--n){
            int next=min(i,min(j,k));
            roc.push_back(next);
            if(next==i)i=2*roc[++ith];
            if(next==j)j=3*roc[++jth];
            if(next==k)k=5*roc[++kth];
        }
        return roc.back();
    }
};
