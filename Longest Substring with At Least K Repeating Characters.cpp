class Solution {
public:
    int longestSubstring(string s, int k) {
        int len=s.size();
        if(len<k)return 0;
        vector<int>roc(26,0);
        for(char c:s)roc[c-'a']++;
        bool flag=true;
        int res=0,newstart=0;
        for(int i=0;i<len;i++){
            if(roc[s[i]-'a']<k){
                res=max(res,longestSubstring(s.substr(newstart,i-newstart),k));
                newstart=i+1;
                flag=false;
            }
        }
        
        return flag?len:max(res,longestSubstring(s.substr(newstart,len-newstart),k));;
    }
};
