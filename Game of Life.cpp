class Solution {
public:
    void check(int i,int j,vector<vector<int>>& board){
        int live=0;
        if(i>0){
            if(j>0&&(board[i-1][j-1]==1||board[i-1][j-1]==2))live++;
            if((board[i-1][j]==1||board[i-1][j]==2))live++;
            if(j<board[0].size()-1&&(board[i-1][j+1]==1||board[i-1][j+1]==2))live++;
        }
        if(j>0&&(board[i][j-1]==1||board[i][j-1]==2))live++;
        if(j<board[0].size()-1&&(board[i][j+1]==1||board[i][j+1]==2))live++;
        if(i<board.size()-1){
            if(j>0&&(board[i+1][j-1]==1||board[i+1][j-1]==2))live++;
            if((board[i+1][j]==1||board[i+1][j]==2))live++;
            if(j<board[0].size()-1&&(board[i+1][j+1]==1||board[i+1][j+1]==2))live++;
        }
        if(board[i][j]&&(live<2||live>3))board[i][j]=2;
        else if(board[i][j]==0&&live==3)board[i][j]=3;
        return;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if(!m)return;
        int n=board[0].size();
        if(!n)return;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                check(i,j,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2)board[i][j]=0;
                else if(board[i][j]==3)board[i][j]=1;
            }
        }
        return;
    }
};
