class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>t;
        vector<int>res(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            int left=0,right=t.size()-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(mid>0&&t[mid-1]<nums[i]&&t[mid]>=nums[i]){
                    left=mid;
                    break;
                }
                if(t[mid]<nums[i])left=mid+1;
                if(t[mid]>=nums[i])right=mid-1;
            }
            t.insert(t.begin()+left,nums[i]);
            res[i]=left;
        }
        return res;
    }
};
