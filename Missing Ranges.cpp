class Solution {
public:
    string generate_ranges(int low,int up){
        if(low==up)return to_string(low);
        else return to_string(low)+"->"+to_string(up);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        if(!n)return {generate_ranges(lower,upper)};
        vector<string>res;
        long long cur=lower;
        for(int i=0;i<n;i++){
            if(nums[i]>cur){
                res.push_back(generate_ranges(cur,nums[i]-1));
                cur=(long long)nums[i]+1;
            }
            else if(nums[i]<cur)continue;
            else cur++;
            if(cur>upper)break;
        }
        if(cur<=(long long)upper)res.push_back(generate_ranges(cur,upper));
        return res;
    }
};
