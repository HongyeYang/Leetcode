class Solution {
public:
    bool isValid(vector<int>&pos,int row,int col){
        for(int i=0;i<row;i++){
            if(pos[i]==col||abs(pos[i]-col)==abs(row-i))return false;
        }
        return true;
    }
    void dfs(vector<int>&pos,int row,int n,vector<vector<string>>&res){
        if(row==n){
            vector<string>cur(n,string(n,'.'));
            for(int i=0;i<n;i++){
                cur[i][pos[i]]='Q';
            }
            res.push_back(cur);
        }
        else{
            for(int col=0;col<n;col++){
                if(isValid(pos,row,col)){
                    pos[row]=col;
                    dfs(pos,row+1,n,res);
                    pos[row]=-1;
                }
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int>pos(n,-1);
        vector<vector<string>>res;
        dfs(pos,0,n,res);
        return res;
    }
};
