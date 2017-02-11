class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size()!=9||board[0].size()!=9)return;
        DFS(board,0,0);
        return;
    }
    bool DFS(vector<vector<char>>&board, int i, int j){
        if(j==9)return DFS(board,i+1,0);
        if(i==9)return true;
        if(board[i][j]=='.'){
            for(int k=1;k<=9;k++){
                board[i][j]='0'+k;
                if(isValid(board,i,j)&&DFS(board,i,j+1))return true;
            }
            board[i][j]='.';
            return false;
        }
        else return DFS(board,i,j+1);
    }
    bool isValid(vector<vector<char>>&board, int i, int j){
        //check in the row
        for(int n=0;n<9;n++){
            if(n!=j&&board[i][j]==board[i][n])return false;
        }
        //check the col
        for(int m=0;m<9;m++){
            if(m!=i&&board[i][j]==board[m][j])return false;
        }
        //check the block
        for(int m=i/3*3;m<i/3*3+3;m++){
            for(int n=j/3*3;n<j/3*3+3;n++){
                if(m!=i&&n!=j&&board[m][n]==board[i][j])return false;
            }
        }
        return true;
    }
};
