class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==1)return nums[0];
        int ppre1=0,pre1=0,cur1=0,ppre2=0,pre2=0,cur2=0;
        for(int i=0;i<len-1;i++){
            cur1=max(pre1,ppre1+nums[i]);
            cur2=max(pre2,ppre2+nums[i+1]);
            ppre1=pre1;
            ppre2=pre2;
            pre1=cur1;
            pre2=cur2;
        }
        return max(cur1,cur2);
    }
};
