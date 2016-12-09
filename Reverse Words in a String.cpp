class Solution {
public:
    void reverseWords(string &s) {
        int len=s.size();
        if(!len)return;
        int start=0;
        while(start<len){
            int end=start;
            while(end<len&&s[end]==' ')end++;
            int flag=end;
            while(end<len&&s[end]!=' ')end++;
            reverse(s.begin()+start,s.begin()+end);
            start=end-flag+1+start;
        }
        while(s.back()==' ')s.pop_back();
        reverse(s.begin(),s.end());
        while(s.back()==' ')s.pop_back();
        return;
    }
};
