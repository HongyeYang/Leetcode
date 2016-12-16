class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens=s.size(),lent=t.size();
        if(!lens)return true;
        if(!lent)return false;
        int i=0;
        char target=s[0];
        for(char c:t){
            if(c==target){
                if(i==lens-1)return true;
                i++;
                target=s[i];
            }
        }
        return false;
    }
};
