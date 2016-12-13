class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)return 0;
        vector<int>roc(amount+1,amount+1);
        roc[0]=0;
        for(int i=1;i<=amount;i++){
            for(int c:coins){
                if(c<=i)roc[i]=min(roc[i-c]+1,roc[i]);
            }
        }
        return roc[amount]>amount?-1:roc[amount];
    }
};
