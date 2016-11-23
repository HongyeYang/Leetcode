class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        if(!len)return {};
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int target=-nums[i];
            int j=i+1,k=len-1;
            while(j<k){
                while(j>i+1&&nums[j]==nums[j-1])j++;
                while(k<len-1&&nums[k]==nums[k+1])k--;
                if(j>=k)break;
                if(nums[j]+nums[k]>target)k--;
                else if(nums[j]+nums[k]<target)j++;
                else{
                    vector<int>cur;
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    cur.push_back(nums[k]);
                    res.push_back(cur);
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};
