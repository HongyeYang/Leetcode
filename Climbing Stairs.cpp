class Solution {
public:
    int climbStairs(int n) {
        int cur=1,pre=1,tep;
        while(n>=2){
            tep=cur;
            cur=cur+pre;
            pre=tep;
            n--;
        }
        return cur;
    }
};
