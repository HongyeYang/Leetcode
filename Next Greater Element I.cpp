class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>roc;
        
        for(int i=0;i<nums.size();i++){
            roc[nums[i]]=i;
        }
        
        for(int i=0;i<findNums.size();i++){
            int start=roc[findNums[i]]+1;
            for(int j=start;j<nums.size();j++){
                if(nums[j]>findNums[i]){
                    res.push_back(nums[j]);
                    break;
                }
            }
            if(res.size()<=i)res.push_back(-1);
        }
        return res;
    }
};
