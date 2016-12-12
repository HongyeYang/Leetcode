class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>roc(26,0);
        for(char c:s)roc[c-'a']++;
        for(char c:t)roc[c-'a']--;
        for(int k:roc)if(k)return false;
        return true;
    }
};
