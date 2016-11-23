class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        if(len<3)return 0;
        sort(nums.begin(),nums.end());
        int res=INT_MAX,ressum=0;
        for(int i=0;i<len-2;i++){
            int j=i+1,k=len-1;
            while(j<k){
                int sums=nums[i]+nums[j]+nums[k];
                if(res>abs(sums-target)){
                    res=abs(sums-target);
                    ressum=sums;
                }
                if(sums<target)j++;
                else if(sums>target)k--;
                else return sums;
            }
        }
        return ressum;
    }
};
