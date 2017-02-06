class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>res;
        int len=nums.size();
        if(len<2)return res;
        int fst[len];
        bool rep[len];
        for(int i=0;i<len;i++){
            fst[i]=res.size();
            rep[i]=false;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<=nums[i]){
                    if(!rep[j])res.push_back({nums[j],nums[i]});
                    for(int k=fst[j];k<fst[j+1];k++){
                        res.push_back(res[k]);
                        res.back().push_back(nums[i]);
                    }
                    if(nums[i]==nums[j]){
                        rep[i]=true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
