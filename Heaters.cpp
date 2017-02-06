class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int res=0;
        int j=0;
        for(int i=0;i<houses.size();i++){
            int cur=abs(houses[i]-heaters[j]);
            while(j<heaters.size()-1&&abs(houses[i]-heaters[j+1])<=cur){
                j++;
                cur=abs(houses[i]-heaters[j]);
            }
            res=max(res,cur);
        }
        return res;
    }
};
