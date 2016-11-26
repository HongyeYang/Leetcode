class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return;
        
        int mid=(len-1)/2;
        int left=0,right=len-1,cur=mid;
        while(cur>=left&&cur<=right){
            if(nums[cur]==0){
                swap(nums[left],nums[cur]);
                left++;
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[right]);
                right--;
            }
            else cur--;
        }
        cur=mid+1;
        while(cur<=right&&cur>=left){
            if(nums[cur]==0){
                swap(nums[left],nums[cur]);
                left++;
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[right]);
                right--;
            }
            else cur++;
        }
        return;
    }
};
