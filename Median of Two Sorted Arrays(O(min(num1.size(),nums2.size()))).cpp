class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n)return findMedianSortedArrays(nums2,nums1);
        if(m==0)return (nums2[n/2]+nums2[(n-1)/2])/2.0;
        int left=0,right=2*m;
        while(left<=right){
            int mid1=(left+right)/2;
            int mid2=m+n-mid1;
            int L1=mid1==0?INT_MIN:nums1[(mid1-1)/2];
            int L2=mid2==0?INT_MIN:nums2[(mid2-1)/2];
            int H1=mid1==2*m?INT_MAX:nums1[mid1/2];
            int H2=mid2==2*n?INT_MAX:nums2[mid2/2];
            
            if(L1>H2)right=mid1-1;
            else if(L2>H1)left=mid1+1;
            else return (max(L1,L2)+min(H1,H2))/2.0;
        }
        return -1;
    }
};
