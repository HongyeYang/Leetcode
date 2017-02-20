class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>roc(nums.begin(),nums.begin()+k);
        auto mid=next(roc.begin(),k/2);
        vector<double>res;
        int i=k;
        for(;i<=nums.size();i++){
            res.push_back(((double)*mid+*next(mid,k%2-1))/2);
            if(i==nums.size())return res;
            roc.insert(nums[i]);
            if(nums[i]<*mid)mid--;
            if(nums[i-k]<=*mid)mid++;
            roc.erase(roc.lower_bound(nums[i-k]));
        }
    }
};
