class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len=nums.size();
        map<int,int>roc;
        int j=0;
        for(int i=0;i<len;i++){
            if(i-j>k&&roc[nums[j]]==j)roc.erase(nums[j++]);
            auto a=roc.lower_bound(nums[i]-t);
            if(a!=roc.end()&& abs(a->first-nums[i])<=t)return true;
            roc[nums[i]]=i;
        }
        return false;
    }
};
