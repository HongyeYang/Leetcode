class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n)return 0;
        vector<int>local(3,0);
        vector<int>global(3,0);
        for(int i=1;i<n;i++){
            for(int j=2;j>=1;j--){
                int diff=prices[i]-prices[i-1];
                local[j]=max(global[j-1]+max(0,diff),local[j]+diff);
                global[j]=max(global[j],local[j]);
            }
        }
        return global[2];
    }
};
