class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)return;
        vector<int>roc(n+m,0);
        int i=0,j=0,k=0;
        for(;k<m+n;k++){
            if(i<m&&(j==n||nums1[i]<=nums2[j])){
                roc[k]=nums1[i];
                i++;
            }
            else{
                roc[k]=nums2[j];
                j++;
            }
        }
        for(k=0;k<m+n;k++){
            if(k<nums1.size())nums1[k]=roc[k];
            else nums1.push_back(roc[k]);
        }
        return;
    }
};
