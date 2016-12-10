class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return false;
        unordered_set<int>roc;
        for(int c:nums){
            if(roc.find(c)!=roc.end())return true;
            roc.insert(c);
        }
        return false;
    }
};
