class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int m=matrix.size();
        if(!m)return res;
        int n=matrix[0].size();
        if(!n)return res;
        int k=m*n,i=0,j=0;
        bool accending=true;
        for(int cur=0;cur<k;cur++){
            res.push_back(matrix[i][j]);
            if((i==0&&accending)||(i==m-1&&(!accending))){
                accending=!accending;
                j++;
                if(j==n){
                    i++;
                    j--;
                }
            }
            else if((j==0&&(!accending))||(j==n-1&&accending)){
                accending=!accending;
                i++;
            }
            else{
                if(accending){
                    i--;
                    j++;
                }
                else{
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};
