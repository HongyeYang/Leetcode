class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2||k<=0)return 0;
        if(k>n/2)return quickProfit(prices);
        vector<int>local(k+1,0);
        vector<int>global(k+1,0);
        for(int i=1;i<n;i++){
            int diff=prices[i]-prices[i-1];
            for(int j=k;j>=1;j--){
                local[j]=max(global[j-1]+max(0,diff),local[j]+diff);
                global[j]=max(global[j],local[j]);
            }
        }
        return global[k];
    }
    
    int quickProfit(vector<int>&prices){
        int res=0;
        for(int i=1;i<prices.size();i++)res+=max(0,prices[i]-prices[i-1]);
        return res;
    }
};
