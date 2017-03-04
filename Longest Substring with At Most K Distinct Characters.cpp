class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len=s.size();
        if(!len||!k)return 0;
        int count=0;
        vector<int>roc(128,0);
        int left=0;
        int res=0;
        for(int i=0;i<len;i++){
            if(roc[s[i]]==0)count++;
            roc[s[i]]++;
            if(count>k){
                res=max(res,i-left);
                while(count>k){
                    roc[s[left]]--;
                    if(roc[s[left]]==0)count--;
                    left++;
                }
            }
        }
        res=max(res,len-left);
        return res;
    }
};
