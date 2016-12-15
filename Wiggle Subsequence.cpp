class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return len;
        bool flag;
        int i=1;
        for(;i<len;i++){
            if(nums[i]!=nums[i-1]){
                flag=nums[i]>nums[0];
                break;
            }
        }
        int res=1,target=nums[0];
        for(;i<len;i++){
            if(flag){
                if(nums[i]>target){
                    res++;
                    target=nums[i];
                    flag=!flag;
                }
                else target=nums[i];
            }
            else{
                if(nums[i]<target){
                    res++;
                    target=nums[i];
                    flag=!flag;
                }
                else target=nums[i];
            }
        }
        return res;
    }
};
