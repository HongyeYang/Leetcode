class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len=nums.size();
        if(len<4)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<len-3;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<len-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int m=j+1,n=len-1,tt=target-nums[i]-nums[j];
                while(m<n){
                    while(m>j+1&&nums[m]==nums[m-1])m++;
                    while(n<len-1&&nums[n]==nums[n+1])n--;
                    if(n<=m)break;
                    if(nums[m]+nums[n]>tt)n--;
                    else if(nums[m]+nums[n]<tt)m++;
                    else{
                        vector<int>curres{nums[i],nums[j],nums[m],nums[n]};
                        res.push_back(curres);
                        m++;n--;
                    }
                }
            }
        }
        return res;
    }
};
