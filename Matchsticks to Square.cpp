class Solution {
public:
    static bool cmp(int a,int b){
        return a>b;
    }
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums.size()<4)return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4)return false;
        int target=sum/4;
        for(int i=0;i<4;i++){
            vector<int>path;
            if(!dfs(nums,target,path,0))return false;
            for(int j=path.size()-1;j>=0;j--){
                nums.erase(nums.begin()+path[j]);
            }
        }
        return true;
    }
    
    bool dfs(vector<int>&nums, int target,vector<int>&path,int start){
        if(target==0)return true;
        if(target<0)return false;
        for(int i=start;i<nums.size();i++){
            path.push_back(i);
            if(dfs(nums,target-nums[i],path,i+1))return true;
            path.pop_back();
        }
        return false;
    }
};
