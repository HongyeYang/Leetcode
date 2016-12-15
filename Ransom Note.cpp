class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>roc(26,0);
        for(auto c:magazine)roc[c-'a']++;
        for(auto c:ransomNote){
            if(--roc[c-'a']<0)return false;
        }
        return true;
    }
};
