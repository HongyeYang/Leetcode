class Solution {
public:
    void DST(vector<vector<char>>& board,int i,int j){
        board[i][j]='Y';
        int m=board.size();
        int n=board[0].size();
        if(i>0&&board[i-1][j]=='O')DST(board,i-1,j);
        if(i<m-1&&board[i+1][j]=='O')DST(board,i+1,j);
        if(j>1&&board[i][j-1]=='O')DST(board,i,j-1);
        if(j<n-1&&board[i][j+1]=='O')DST(board,i,j+1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(!m)return;
        int n=board[0].size();
        if(!n)return;
        //left
        for(int i=0;i<m;i++)if(board[i][0]=='O')DST(board,i,0);
        //right
        for(int i=0;i<m;i++)if(board[i][n-1]=='O')DST(board,i,n-1);
        //up
        for(int i=0;i<n;i++)if(board[0][i]=='O')DST(board,0,i);
        //down
        for(int i=0;i<n;i++)if(board[m-1][i]=='O')DST(board,m-1,i);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Y')board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
            }
        }
        return;
    }
};
