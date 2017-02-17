class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss=1;
        int i=0,res=0;
        while(miss<=n){
            if(i<nums.size()&&miss>=nums[i])miss+=nums[i++];
            else{
                res++;
                miss+=miss;
            }
        }
        return res;
    }
};
