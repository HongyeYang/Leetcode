class NumMatrix {
public:
    vector<vector<int>>roc;
    NumMatrix(vector<vector<int>> &matrix) {
        int m=matrix.size();
        if(!m)return;
        int n=matrix[0].size();
        if(!n)return;
        roc.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                roc[i][j]=roc[i-1][j]+roc[i][j-1]-roc[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return roc[row2+1][col2+1]-roc[row1][col2+1]-roc[row2+1][col1]+roc[row1][col1];
    }
};
