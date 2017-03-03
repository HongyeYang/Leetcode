class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        m=matrix.size()+1;
        if(m<2)return;
        n=matrix[0].size()+1;
        if(n<2)return;
        c.resize(m,vector<int>(n,0));
        e.resize(m-1,vector<int>(n-1,0));
        
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                add(i+1,j+1,matrix[i][j]);
                e[i][j]=matrix[i][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff=val-e[row][col];
        add(row+1,col+1,diff);
        e[row][col]=val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_sum(row2+1,col2+1)-get_sum(row1,col2+1)-get_sum(row2+1,col1)+get_sum(row1,col1);
    }
private:
vector<vector<int>>c;
vector<vector<int>>e;
int m=0;
int n=0;
int lowbit(int p){
    return p&(-p);
}
void add(int row, int col,int val){
    for(int i=row;i<m;i+=lowbit(i)){
        for(int j=col;j<n;j+=lowbit(j)){
            c[i][j]+=val;
        }
    }
}
int get_sum(int row,int col){
    int res=0;
    for(int i=row;i>0;i-=lowbit(i)){
        for(int j=col;j>0;j-=lowbit(j)){
            res+=c[i][j];
        }
    }
    return res;
}
};
