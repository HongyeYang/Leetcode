class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        int mx=INT_MIN,mn=INT_MAX;
        for(int d:nums){
            mx=max(mx,d);
            mn=min(mn,d);
        }
        
        int size=(mx-mn)/n+1;
        int bucket_size=(mx-mn)/size+1;
        vector<int>maxBucket(bucket_size,INT_MIN);
        vector<int>minBucket(bucket_size,INT_MAX);
        unordered_set<int>valid_bucket;
        
        for(int d:nums){
            int index=(d-mn)/size;
            maxBucket[index]=max(d,maxBucket[index]);
            minBucket[index]=min(d,minBucket[index]);
            valid_bucket.insert(index);
        }
        
        int pre=0,res=0;
        for(int i=1;i<bucket_size;i++){
            if(valid_bucket.find(i)==valid_bucket.end())continue;
            res=max(minBucket[i]-maxBucket[pre],res);
            pre=i;
        }
        return res;
    }
};
