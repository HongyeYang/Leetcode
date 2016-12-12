class Solution {
public:
    int numSquares(int n) {
        vector<int>roc(n+1,INT_MAX);
        roc[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                roc[i]=min(roc[i],1+roc[i-j*j]);
            }
        }
        return roc[n];
    }
};
