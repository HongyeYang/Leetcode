class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int cur=nums[0];
        for(int i=0;i<=cur;i++){
            cur=max(cur,i+nums[i]);
            if(cur>=len-1)return true;
        }
        return false;
    }
};
