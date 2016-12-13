class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len=nums.size();
        auto midpt=nums.begin()+len/2;
        nth_element(nums.begin(),midpt,nums.end());
        int mid=*midpt;
        #define A(i) nums[(1+2*i)%(len|1)]
        int i=0,j=0,k=len-1;
        while(i<=k){
            if(A(i)>mid)swap(A(i++),A(j++));
            else if(A(i)<mid)swap(A(i),A(k--));
            else i++;
        }
        return;
    }
};
