class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mx;
        int i=0;
        for(;i<k-1;i++)mx.insert(nums[i]);
        
        vector<int>res;
        for(;i<nums.size();i++){
            mx.insert(nums[i]);
            res.push_back(*mx.rbegin());
            mx.erase(mx.find(nums[i-k+1]));
        }
        return res;
    }
};
