class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>roc;
        for(int c:nums){
            auto it=lower_bound(roc.begin(),roc.end(),c);
            if(it==roc.end())roc.push_back(c);
            else *it=c;
        }
        return roc.size();
    }
};
