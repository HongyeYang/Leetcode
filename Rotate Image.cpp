class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(!n)return;
        int c=0;
        while(c<=n/2){
            for(int i=c;i<n-1-c;i++){
                int tep=matrix[c][i];
                matrix[c][i]=matrix[n-1-i][c];
                matrix[n-1-i][c]=matrix[n-1-c][n-1-i];
                matrix[n-1-c][n-1-i]=matrix[i][n-1-c];
                matrix[i][n-1-c]=tep;
            }
            c++;
        }
        return;
    }
};
