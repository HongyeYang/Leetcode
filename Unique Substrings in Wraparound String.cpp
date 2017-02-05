class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int>roc(26,0);
        int len=0;
        for(int i=0;i<p.size();i++){
            if(i>0&&(p[i]==p[i-1]+1||p[i]==p[i-1]-25))len++;
            else len=1;
            roc[p[i]-'a']=max(len,roc[p[i]-'a']);
        }
        int res=0;
        for(int i:roc)res+=i;
        return res;
    }
};
