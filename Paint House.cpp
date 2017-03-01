class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len=costs.size();
        if(!len)return 0;
        for(int i=1;i<len;i++){
            costs[i][0]+=min(costs[i-1][1],costs[i-1][2]);
            costs[i][1]+=min(costs[i-1][0],costs[i-1][2]);
            costs[i][2]+=min(costs[i-1][0],costs[i-1][1]);
        }
        
        return min(costs[len-1][0],min(costs[len-1][1],costs[len-1][2]));
    }
};
