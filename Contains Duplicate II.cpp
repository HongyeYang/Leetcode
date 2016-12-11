class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<2)return false;
        unordered_map<int,int>roc;
        for(int i=0;i<len;i++){
            if(roc.find(nums[i])==roc.end()){
                roc[nums[i]]=i;
            }
            else{
                if(i-roc[nums[i]]<=k)return true;
                else roc[nums[i]]=i;
            }
        }
        return false;
    }
};
