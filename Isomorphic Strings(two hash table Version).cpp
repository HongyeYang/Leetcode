class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1=s.size(),len2=t.size();
        if(len1!=len2)return false;
        unordered_map<char,char>roc;
        unordered_map<char,char>eoc;
        for(int i=0;i<len1;i++){
            if((roc.find(s[i])!=roc.end())&&(eoc.find(t[i])!=eoc.end())){if(t[i]!=roc[s[i]]||s[i]!=eoc[t[i]])return false;}
            else if((roc.find(s[i])==roc.end())&&(eoc.find(t[i])==eoc.end())){
                roc[s[i]]=t[i];
                eoc[t[i]]=s[i];
            }
            else return false;
        }
        return true;
    }
};
