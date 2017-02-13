class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int res=0;
        for(int n:nums){
            if(s.count(n)==0)continue;
            s.erase(n);
            int pre=n-1,next=n+1;
            while(s.count(pre))s.erase(pre--);
            while(s.count(next))s.erase(next++);
            res=max(next-pre-1,res);
        }
        return res;
    }
};
