class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger>=desiredTotal)return true;
        int sum=(1+maxChoosableInteger)*maxChoosableInteger/2;
        if(sum<desiredTotal)return false;
        
        vector<int>roc(1<<maxChoosableInteger,-1);
        
        return DFS(maxChoosableInteger,desiredTotal,0,roc);
    }
    bool DFS(int &m,int d,int used,vector<int>&roc){
        if(roc[used]!=-1)return roc[used];
        for(int i=0;i<m;i++){
            if((1<<i)&used)continue;
            int cur=used|(1<<i);
            if((i+1)>=d||!DFS(m,d-i-1,cur,roc)){
                roc[used]=1;
                return true;
            }
        }
        roc[used]=0;
        return false;
    }
};
