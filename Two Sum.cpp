class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>roc;
        int len=nums.size();
        vector<int>res;
        if(!len)return res;
        for(int i=0;i<len;i++)roc[nums[i]]=i;
        for(int i=0;i<len;i++){
            int tt=target-nums[i];
            if(roc.find(tt)!=roc.end()&&roc[tt]!=i){
                res.push_back(i);
                res.push_back(roc[target-nums[i]]);
                return res;
            }
        }
        return res;
    }
};
