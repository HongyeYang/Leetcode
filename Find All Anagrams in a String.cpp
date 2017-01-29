class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int plen=p.size();
        int slen=s.size();
        if(slen<plen)return {};
        vector<int>roc(26,0);
        for(char &c:p)roc[c-'a']--;
        for(int i=0;i<plen;i++){
            roc[s[i]-'a']++;
        }
        int flag=0;
        vector<int>res;
        for(int c:roc){
            if(c)flag++;
        }
        if(!flag)res.push_back(0);
        for(int i=plen;i<slen;i++){
            roc[s[i]-'a']++;
            if(roc[s[i]-'a']==1)flag++;
            if(roc[s[i]-'a']==0)flag--;
            roc[s[i-plen]-'a']--;
            if(roc[s[i-plen]-'a']==-1)flag++;
            if(roc[s[i-plen]-'a']==0)flag--;
            if(!flag)res.push_back(i-plen+1);
        }
        return res;
    }
};
