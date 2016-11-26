class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>roc(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                roc[j]=roc[j]+roc[j-1];
            }
        }
        return roc.back();
    }
};
