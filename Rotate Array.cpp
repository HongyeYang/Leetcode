class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if(!len||!k)return;
        k=k%len;
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
        return;
    }
};
