class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(!len)return 0;
        int minnum=INT_MAX,res=0;
        for(int i=0;i<len;i++){
            res=max(res,prices[i]-minnum);
            minnum=min(prices[i],minnum);
        }
        return res;
    }
};
