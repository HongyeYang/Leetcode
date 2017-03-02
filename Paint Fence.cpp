class Solution {
public:
    int numWays(int n, int k) {
        if(!n)return 0;
        int same=0,diff=k;
        for(int i=2;i<=n;i++){
            int t=diff;
            diff=(k-1)*(same+diff);
            same=t;
        }
        return diff+same;
    }
};
