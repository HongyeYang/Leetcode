class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>roc;
        for(int c:nums1)roc.insert(c);
        vector<int>res;
        for(int c:nums2){
            if(roc.find(c)!=roc.end()){
                res.push_back(c);
                roc.erase(c);
            }
        }
        return res;
    }
};
