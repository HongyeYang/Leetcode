class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size();
        if(!m)return board;
        int n=board[0].size();
        if(!n)return board;
        
        vector<int>dir={-1,-1,0,-1,1,1,0,1,-1};
        reveal(board,click[0],click[1],m,n,dir);
        return board;
    }
    void reveal(vector<vector<char>>&board, int i,int j,int &m,int &n,vector<int>&dir){
        if(board[i][j]=='M'){
            board[i][j]='X';
            return;
        }
        int cnt=0;
        for(int k=0;k<8;k++){
            int ni=i+dir[k];
            int nj=j+dir[k+1];
            if(ni>=0&&ni<m&&nj>=0&&nj<n&&board[ni][nj]=='M')cnt++;
        }
        
        if(cnt>0){
            board[i][j]='0'+cnt;
        }
        else{
            board[i][j]='B';
            for(int k=0;k<8;k++){
                int ni=i+dir[k];
                int nj=j+dir[k+1];
                if(ni>=0&&ni<m&&nj>=0&&nj<n&&board[ni][nj]=='E')reveal(board,ni,nj,m,n,dir);
            }
        }
        return;
    }
};
