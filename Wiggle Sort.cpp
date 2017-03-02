class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(!n)return;
        auto midpos=nums.begin()+(n-1)/2;
        nth_element(nums.begin(),midpos,nums.end());
        int mid=*midpos;
        int j=n-1;
        int pos=0;
        while(pos<=(n-1)/2){
            if(nums[pos]<=mid)pos++;
            else{
                swap(nums[pos],nums[j--]);
            }
        }
        int i=1;
        j=n-1;
        if(n%2==0)j--;
        for(;i<j;i+=2,j-=2){
            swap(nums[i],nums[j]);
        }
        return;
    }
};
