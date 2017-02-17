class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>res(k,0);
        for(int i=max(0,k-(int)nums2.size());i<=min((int)nums1.size(),k);i++){
            res=max(res,merge(findKElement(nums1,i),findKElement(nums2,k-i)));
        }
        return res;
    }
    
    vector<int> findKElement(vector<int>&nums,int k){
        if(!k)return {};
        if(k==nums.size())return nums;
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(!res.empty()&&(res.back()<nums[i])&&((int)res.size()>(k-(int)nums.size()+i)))res.pop_back();
            res.push_back(nums[i]);
        }
        res.resize(k);
        return res;
    }

    vector<int> merge(vector<int>n1,vector<int>n2){
        vector<int>res;
        int i=0,j=0;
        for(int k=0;k<n1.size()+n2.size();k++){
            if(greater(n1,i,n2,j))res.push_back(n1[i++]);
            else res.push_back(n2[j++]);
        }
        return res;
    }
    
    //decide if n1>n2
    bool greater(vector<int>&n1,int i,vector<int>&n2,int j){
        while(i<n1.size()&&j<n2.size()&&n1[i]==n2[j]){i++;j++;}
        return j==n2.size()||(i<n1.size()&&n1[i]>n2[j]);
    }
    
};
