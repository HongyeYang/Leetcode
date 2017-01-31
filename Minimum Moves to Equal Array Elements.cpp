class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int min_num=nums[0];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_num){
                res+=(i*(min_num-nums[i]));
                min_num=nums[i];
            }
            else res+=(nums[i]-min_num);
        }
        return res;
    }
};
