class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len<3)return len;
        int res=1,count=1;
        for(int i=1;i<len;i++){
            if(nums[i]==nums[i-1]){
                if(count<2){
                    nums[res]=nums[i];
                    count++;
                    res++;
                }
                else count++;
            }
            else{
                nums[res]=nums[i];
                count=1;
                res++;
            }
        }
        return res;
    }
};
