class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       int len1=nums1.size(),len2=nums2.size();
       if(!len1||!len2||!k)return {};
       bool flag=true;
       if(len1<len2){
           swap(nums1,nums2);
           swap(len1,len2);
           flag=false;
       }
       vector<pair<int,int>>res;
       vector<int>idx(len2,0);
       int cnt=min(len1*len2,k);
       for(int i=0;i<cnt;i++){
           int sum=INT_MAX,t=0;
           for(int j=0;j<len2;j++){
               if(idx[j]<len1&&nums1[idx[j]]+nums2[j]<sum){
                   sum=nums1[idx[j]]+nums2[j];
                   t=j;
               }
           }
           if(flag)res.push_back({nums1[idx[t]],nums2[t]});
           else res.push_back({nums2[t],nums1[idx[t]]});
           idx[t]++;
       }
        return res;
    }
};
