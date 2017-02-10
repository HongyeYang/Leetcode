class Solution {
public:
    int findKthElement(vector<int>& nums1, int start1,int l1,vector<int>&nums2,int start2,int l2,int k){
        if(l1<l2)return findKthElement(nums2,start2,l2,nums1,start1,l1,k);
        if(l2==0)return nums1[start1+k-1];
        if(k==1)return min(nums1[start1],nums2[start2]);
        
        int j=min(k/2,l2);
        int i=k-j;
        if(nums1[start1+i-1]<nums2[start2+j-1])return findKthElement(nums1,start1+i,l1-i,nums2,start2,j,k-i);
        else return findKthElement(nums1,start1,i,nums2,start2+j,l2-j,k-j);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if((m+n)&1)return findKthElement(nums1,0,m,nums2,0,n,(m+n+1)/2);
        else return (findKthElement(nums1,0,m,nums2,0,n,(m+n)/2)+findKthElement(nums1,0,m,nums2,0,n,(m+n)/2+1))/2.0;
    }
};
