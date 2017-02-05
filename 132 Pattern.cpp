class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len=nums.size();
        if(len<3)return false;
        int sec=INT_MIN;
        stack<int>fir;
        for(int i=len-1;i>=0;i--){
            if(nums[i]<sec)return true;
            else{
                while(!fir.empty()&&fir.top()<nums[i]){
                    sec=max(sec,fir.top());
                    fir.pop();
                }
                fir.push(nums[i]);
            }
        }
        return false;
        
    }
};
