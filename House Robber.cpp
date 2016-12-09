class Solution {
public:
    int rob(vector<int>& nums) {
        int cur=0,pre=0,ppre=0;
        for(int c:nums){
            cur=max(pre,ppre+c);
            ppre=pre;
            pre=cur;
        }
        return cur;
    }
};
