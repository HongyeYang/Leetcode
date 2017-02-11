class Solution {
public:
    int totalNQueens(int n) {
        vector<int>pos(n,-1);
        int res=0;
        dfs(pos,0,res,n);
        return res;
    }
    void dfs(vector<int>&pos,int row,int&res,int &n){
        if(row==n)res++;
        else{
            for(int col=0;col<n;col++){
                if(isValid(pos,row,col)){
                    pos[row]=col;
                    dfs(pos,row+1,res,n);
                    pos[row]=-1;
                }
            }
        }
        return;
    }
    bool isValid(vector<int>&pos,int row,int col){
        for(int i=0;i<row;i++){
            if(pos[i]==col||abs(pos[i]-col)==abs(row-i))return false;
        }
        return true;
    }
};
