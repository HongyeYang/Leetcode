class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>roc;
        int len=s.size();
        if(!len)return 0;
        int res=0,bord=0,cur=0;
        for(int i=0;i<len;i++){
            if(roc.find(s[i])==roc.end()){
                cur++;
                roc[s[i]]=i;
            }
            else{
                bord=max(bord,roc[s[i]]);
                res=max(res,cur);
                cur=i-bord;
                roc[s[i]]=i;
            }
        }
        res=max(cur,res);
        return res;
    }
};
