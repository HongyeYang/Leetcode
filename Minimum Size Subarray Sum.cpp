class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len=nums.size();
        if(!len)return 0;
        int start=0, bord=0,sum=0,res=len+1,cnum=0;
        while(bord<len){
            while(bord<len&&sum<s){
                sum+=nums[bord++];
                cnum++;
            }
            while(start<bord&&sum>=s){
                sum-=nums[start++];
                cnum--;
            }
            res=min(res,cnum+1);
        }
        return res>len?0:res;
    }
};
