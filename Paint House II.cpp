class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        if(!n)return 0;
        int k=costs[0].size();
        if(!k)return 0;
        int smallest=100000,smallestIdx=-1,secSmallest=100000;
        for(int j=0;j<k;j++){
            if(smallest>=costs[0][j]){
                secSmallest=smallest;
                smallest=costs[0][j];
                smallestIdx=j;
            }
            else if(costs[0][j]<secSmallest)secSmallest=costs[0][j];
        }
        for(int i=1;i<n;i++){
            int n_smallest=10000000,n_smallestIdx=-1,n_secSmallest=10000000;
            for(int j=0;j<k;j++){
                if(j==smallestIdx)costs[i][j]+=secSmallest;
                else costs[i][j]+=smallest;
                if(costs[i][j]<=n_smallest){
                    n_secSmallest=n_smallest;
                    n_smallest=costs[i][j];
                    n_smallestIdx=j;
                }
                else if(costs[i][j]<n_secSmallest)n_secSmallest=costs[i][j];
            }
            smallest=n_smallest;
            smallestIdx=n_smallestIdx;
            secSmallest=n_secSmallest;
        }
        return smallest;
    }
};
