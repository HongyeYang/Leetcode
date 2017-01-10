class Solution {
private:
vector<pair<int,int>>res;
public:
    void DFS(vector<vector<int>>& matrix, vector<vector<char>>&roc,int i, int j,char sign){
        int m=matrix.size(),n=matrix[0].size();
        if(sign=='t'&&roc[i][j]=='p')res.push_back({i,j});
        roc[i][j]=sign;
        if(i>0&&roc[i-1][j]!=sign&&matrix[i-1][j]>=matrix[i][j])DFS(matrix,roc,i-1,j,sign);
        if(i<m-1&&roc[i+1][j]!=sign&&matrix[i+1][j]>=matrix[i][j])DFS(matrix,roc,i+1,j,sign);
        if(j>0&&roc[i][j-1]!=sign&&matrix[i][j-1]>=matrix[i][j])DFS(matrix,roc,i,j-1,sign);
        if(j<n-1&&roc[i][j+1]!=sign&&matrix[i][j+1]>=matrix[i][j])DFS(matrix,roc,i,j+1,sign);
        return;
        
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m)return {};
        int n=matrix[0].size();
        if(!n)return {};
        vector<vector<char>>roc(m,vector<char>(n,'a'));
        //pacific
        for(int i=0;i<m;i++){
            DFS(matrix,roc,i,0,'p');
        }
        for(int j=1;j<n;j++){
            DFS(matrix,roc,0,j,'p');
        }
        
        //atlantic
        for(int i=0;i<m;i++){
            DFS(matrix,roc,i,n-1,'t');
        }
        for(int j=0;j<n-1;j++){
            DFS(matrix,roc,m-1,j,'t');
        }
        
        return res;
        
    }
};
