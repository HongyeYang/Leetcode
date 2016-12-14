class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>roc;
        for(auto c:nums)roc[c]++;
        vector<vector<int>>bucket(nums.size(),vector<int>{});
        vector<int>res;
        for(auto it:roc){
            bucket[it.second-1].push_back(it.first);
        }
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                res.push_back(bucket[i][j]);
                if(res.size()==k)return res;
            }
        }
        return res;
    }
};
