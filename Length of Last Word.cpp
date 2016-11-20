class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        if(!len)return 0;
        int i=len-1;
        while(i>=0&&s[i]==' ')i--;
        int res=0;
        while(i>=0&&s[i]!=' '){res++;i--;}
        return res;
    }
};
