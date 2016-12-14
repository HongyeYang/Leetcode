class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>roc;
        for(int c:nums1)roc[c]++;
        vector<int>res;
        for(int c:nums2){
            if(roc.find(c)!=roc.end()){
                if(roc[c]-->0)res.push_back(c);
            }
        }
        return res;
    }
};
