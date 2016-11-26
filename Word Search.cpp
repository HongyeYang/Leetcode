class Solution {
public:
    bool DST(vector<vector<char>>&board, vector<vector<bool>>&used,string word,int i,int j){
        if(!word.size())return true;
        char c=word[0];
        //up
        if(i>0&&used[i-1][j]&&board[i-1][j]==c){
            used[i-1][j]=false;
            if(DST(board,used,word.substr(1),i-1,j))return true;
            used[i-1][j]=true;
        }
        //down
        if(i<board.size()-1&&used[i+1][j]&&board[i+1][j]==c){
            used[i+1][j]=false;
            if(DST(board,used,word.substr(1),i+1,j))return true;
            used[i+1][j]=true;
        }
        //left
        if(j>0&&used[i][j-1]&&board[i][j-1]==c){
            used[i][j-1]=false;
            if(DST(board,used,word.substr(1),i,j-1))return true;
            used[i][j-1]=true;
        }
        //right
        if(j<board[0].size()-1&&used[i][j+1]&&board[i][j+1]==c){
            used[i][j+1]=false;
            if(DST(board,used,word.substr(1),i,j+1))return true;
            used[i][j+1]=true;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(!word.size())return true;
        int m=board.size();
        if(!m)return false;
        int n=board[0].size();
        if(!n)return false;
        vector<vector<bool>>used(m,vector<bool>(n,true));
        char c=word[0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==c){
                    used[i][j]=false;
                    if(DST(board,used,word.substr(1),i,j))return true;
                    used[i][j]=true;
                }
            }
        }
        return false;
    }
};
