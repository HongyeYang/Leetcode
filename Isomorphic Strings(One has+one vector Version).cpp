class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1=s.size(),len2=t.size();
        if(len1!=len2)return false;
        unordered_map<char,char>roc;
        vector<bool>lt(256,true);
        for(int i=0;i<len1;i++){
            if(roc.find(s[i])!=roc.end()){
                if(roc[s[i]]!=t[i])return false;
            }
            else{
                if(!lt[t[i]])return false;
                roc[s[i]]=t[i];
                lt[t[i]]=false;
            }
        }
        return true;
    }
};
