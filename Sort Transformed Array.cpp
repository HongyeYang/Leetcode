class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int>res;
        double duichenzhou=a==0?nums.back()+1:-(double)b/(2*a);
        
        auto mid=lower_bound(nums.begin(),nums.end(),duichenzhou);
        if(mid==nums.end()){
            for(int i=nums.size()-1;i>=0;i--)res.push_back(nums[i]);
        }
        else if(mid==nums.begin()){
            res=nums;
        }
        else{
            int left=mid-nums.begin()-1,right=left+1;
            while(left>=0&&right<nums.size()){
                if(abs(nums[left]-duichenzhou)<abs(nums[right]-duichenzhou))res.push_back(nums[left--]);
                else res.push_back(nums[right++]);
            }
            while(left>=0){
                res.push_back(nums[left--]);
            }
            while(right<nums.size()){
                res.push_back(nums[right++]);
            }
        }
        if(a<0||(a==0&&b>0))reverse(res.begin(),res.end());
        get_result(res,a,b,c);
        return res;
    }
    void get_result(vector<int>&res,int&a,int&b,int&c){
        for(int i=0;i<res.size();i++){
            res[i]=a*res[i]*res[i]+b*res[i]+c;
        }
        return;
    }
};
