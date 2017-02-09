class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
        stack<int>s;
        for(int i=len-1;i>=0;i--){
            s.push(nums[i]);
        }
        vector<int>res(len,0);
        for(int i=len-1;i>=0;i--){
            while(!s.empty()&&s.top()<=nums[i]){
                s.pop();
            }
            if(s.empty())res[i]=-1;
            else res[i]=s.top();
            s.push(nums[i]);
        }
        return res;
    }
};
