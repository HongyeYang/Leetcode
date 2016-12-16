class Solution {
public:
    int firstUniqChar(string s) {
        int len=s.size();
        if(!len)return -1;
        vector<int>roc(26,0);
        for(char c:s)roc[c-'a']++;
        for(int i=0;i<len;i++){
            if(roc[s[i]-'a']==1)return i;
        }
        return -1;
    }
};
