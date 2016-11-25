class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9||board[0].size()!=9)return false;
        //rows
        for(int i=0;i<9;i++){
            vector<int>row(9,0);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(row[board[i][j]-'1']>0)return false;
                else row[board[i][j]-'1']++;
            }
        }
        
        //cols
        for(int j=0;j<9;j++){
            vector<int>col(9,0);
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')continue;
                if(col[board[i][j]-'1']>0)return false;
                else col[board[i][j]-'1']++;
            }
        }
        //blocks
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                vector<int>roc(9,0);
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[m*3+i][n*3+j]=='.')continue;
                        if(roc[board[m*3+i][n*3+j]-'1']>0)return false;
                        else roc[board[m*3+i][n*3+j]-'1']++;
                    }
                }
            }
        }
        return true;
    }
