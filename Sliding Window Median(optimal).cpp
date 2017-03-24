class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>numset;
        int i=0;
        for(;i<k;++i){
            numset.insert(nums[i]);
        }
        
        int pos=(k-1)/2;
        auto mid=numset.begin();
        for(int j=0;j<pos;++j)++mid;
        vector<double>res;
        for(int j=0;i<=nums.size();++i,++j){
            if(k&1){
                res.push_back(*mid);
            }
            else{
                auto it=mid;
                ++it;
                res.push_back(((double)*mid+((double)*it-*mid)/2.0));
            }
            if(i==(int)nums.size())break;
            
            numset.insert(nums[i]);
            if(nums[i]<*mid)--mid;
            
            auto rm=numset.find(nums[j]);
            if(nums[j]<=*mid)++mid;
            numset.erase(rm);
        }
        return res;
    }
};
