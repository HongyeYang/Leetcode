class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int c:nums){
            int idx = abs(c)-1;
            if(nums[idx]>0)nums[idx]=-nums[idx];
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)res.push_back(i+1);
        }
        return res;
    }
};
