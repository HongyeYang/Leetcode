class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n,0);
        cols.resize(n,0);
        diag_lt=0;
        diag_rt=0;
        s=n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add=player==1?1:-1;
        rows[row]+=add;
        cols[col]+=add;
        if(row==col)diag_lt+=add;
        if((row+col)==(s-1))diag_rt+=add;
        if(abs(rows[row])==s||abs(cols[col])==s||abs(diag_lt)==s||abs(diag_rt)==s)return player;
        return 0;
    }
private:
vector<int>rows;
vector<int>cols;
int diag_lt;
int diag_rt;
int s=0;
};

