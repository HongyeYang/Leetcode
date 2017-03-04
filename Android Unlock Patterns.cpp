class Solution {
public:
    int numberOfPatterns(int m, int n) {
        //init jump matrix
        vector<vector<int>>jump(10,vector<int>(10,0));
        jump[1][3]=jump[3][1]=2;
        jump[4][6]=jump[6][4]=5;
        jump[7][9]=jump[9][7]=8;
        jump[1][7]=jump[7][1]=4;
        jump[2][8]=jump[8][2]=5;
        jump[3][9]=jump[9][3]=6;
        jump[1][9]=jump[9][1]=5;
        jump[3][7]=jump[7][3]=5;
        
        vector<bool>visited(10,false);
        int res=0;

        res+=4*(dfs(1,1,m,n,jump,visited,0));
        res+=4*(dfs(2,1,m,n,jump,visited,0));
        res+=dfs(5,1,m,n,jump,visited,0);
        
        return res;
    }
    int dfs(int num, int len,int &m, int &n, vector<vector<int>>&jump, vector<bool>&visited,int res){
        if(len>=m)res++;
        if(len>=n)return res;
        len++;
        visited[num]=true;
        for(int i=1;i<10;i++){
            if(!visited[i]&&(jump[num][i]==0||visited[jump[num][i]])){
                res+=dfs(i,len,m,n,jump,visited,0);
            }
        }
        visited[num]=false;
        return res;
    }
};
