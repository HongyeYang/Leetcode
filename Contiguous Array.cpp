class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)nums[i]=-1;
        }
        unordered_map<int,int>roc;
        roc[0]=-1;
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(roc.count(sum))res=max(res,i-roc[sum]);
            else roc[sum]=i;
        }
        return res;
    }
};
