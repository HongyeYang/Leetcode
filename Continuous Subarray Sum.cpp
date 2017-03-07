class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(!k){
            int sum=nums[0];
            for(int i=1;i<nums.size();i++){
                sum+=nums[i];
                if(sum==0)return true;
            }
            return false;
        }
        unordered_set<int>sums;
        int sum=nums[0];
        int presum=0;
        for(int i=1;i<nums.size();i++){
            sums.insert(presum%k);
            presum=sum;
            sum+=nums[i];
            if(sums.count(sum%k))return true;

        }
        return false;
    }
};
