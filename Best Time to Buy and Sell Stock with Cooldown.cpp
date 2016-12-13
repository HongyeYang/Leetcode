class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<2)return 0;
        int buy=INT_MIN,presell=0,sell=0,ppsell=0;
        for(int i=0;i<len;i++){
            sell=max(sell,buy+prices[i]);
            buy=max(buy,ppsell-prices[i]);
            ppsell=presell;
            presell=sell;
        }
        return sell;
    }
};
