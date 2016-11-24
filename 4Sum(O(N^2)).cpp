class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len=nums.size();
        if(len<4)return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>>roc;
        vector<vector<int>>res;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                roc[nums[i]+nums[j]].push_back({i,j});
            }
        }
        
        for(int i=0;i<len-1;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<len;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                if(roc.find(target-nums[i]-nums[j])!=roc.end()){
                    vector<pair<int,int>>& pairs=roc[target-nums[i]-nums[j]];
                    bool fir=true;
                    for(auto &c:pairs){
                        if(c.first<=j)continue;
                        if(fir||nums[c.first]!=(res.back()[2])){
                        res.push_back({nums[i],nums[j],nums[c.first],nums[c.second]});
                        fir=false;
                        }
                    }
                }
            }
        }
        return res;
    }
};
