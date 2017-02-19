class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        //corner cases
        int n=A.size();
        if(n<3)return 0;
        //init the data structure
        vector<vector<int>>dp(n,vector<int>(n,0));
        unordered_map<long,set<int>>roc;
        for(int i=0;i<n;i++){
            roc[(long)A[i]].insert(i);
        }
        int res=0;
        
        //dp travers
        for(int j=1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                long pre=(long)A[j]+A[j]-A[k];
                if(!roc.count(pre))continue;
                for(int i:roc[pre]){
                    if(i>=j)break;
                    dp[j][k]+=(dp[i][j]+1);
                }
                res+=dp[j][k];
            }
        }
        return res;
    }
};
