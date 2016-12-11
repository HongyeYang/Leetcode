class Solution {
public:
    pair<int,int> partition(vector<int>& nums, int start, int end){
        int n=start+1;
        for(int i=start+1;i<=end;i++){
            if(nums[i]>nums[start])swap(nums[n++],nums[i]);
        }
        n--;
        swap(nums[start],nums[n]);
        int m=n;
        while(n+1<=end&&nums[n+1]==nums[m])n++;
        return {m,n};
    }
    int FKL(vector<int>& nums, int k, int start, int end){
        if(start>=end)return nums[end];
        pair<int,int>step=partition(nums,start,end);
        if(k<step.first+1)return FKL(nums,k,start,step.first-1);
        if(k>step.second+1)return FKL(nums,k,step.second+1,end);
        else return nums[step.first];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        return FKL(nums,k,0,len-1);
    }
};
