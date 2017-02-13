class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1=s1.size(),len2=s2.size();
        if(len1!=len2)return false;
        if(s1==s2)return true;
        vector<int>roc(26,0);
        for(char c:s1)roc[c-'a']++;
        for(char c:s2)roc[c-'a']--;
        for(int k:roc)if(k)return false;
        
        for(int i=1;i<len1;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))return true;
            if(isScramble(s1.substr(0,i),s2.substr(len1-i))&&isScramble(s1.substr(i),s2.substr(0,len1-i)))return true;
        }
        return false;
        
    }
};
