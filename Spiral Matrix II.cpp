class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        if(!n)return res;
        int a=0,lim=(n+1)/2,fill=1;
        for(;a<lim;a++){
            int up=a,down=n-1-a,left=a,right=n-1-a;
            for(int i=left;i<right;i++){res[up][i]=fill;fill++;}
            for(int i=up;i<down;i++){res[i][right]=fill;fill++;}
            for(int i=right;i>left;i--){res[down][i]=fill;fill++;}
            for(int i=down;i>up;i--){res[i][left]=fill;fill++;}
        }
        if(n&1)res[a-1][a-1]=fill;
        return res;
    }
};
