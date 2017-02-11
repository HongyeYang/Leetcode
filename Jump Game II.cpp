class Solution {
public:
    int jump(vector<int>& nums) {
        int R=0,step=0,nR=0;
        if(nums.size()==1)return 0;
        for(int i=0;i<nums.size();i++){
            if(R<i){
                step++;
                R=nR;
            }
            nR=max(nR,i+nums[i]);
            if(nR>=nums.size()-1)return step+1;
        }
        return step;
    }
};
