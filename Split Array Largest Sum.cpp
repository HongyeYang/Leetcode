class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left=0,right=0;
        for(int n:nums){
            left=max(left,n);
            right+=n;
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(isValidCut(nums,m,mid))right=mid;
            else left=mid+1;
        }
        return left;
    }
    bool isValidCut(vector<int>&nums,int m,int upperSum){
        int sum=0,cnt=1;
        for(int n:nums){
            sum+=n;
            if(sum>upperSum){
                sum=n;
                cnt++;
                if(cnt>m)return false;
            }
        }
        return true;
    }
};
