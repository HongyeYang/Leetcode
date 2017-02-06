class Solution {
public:
    int magicalString(int n) {
       string s="122";
       int i=2;
       char next='1';
       while(s.size()<n){
           string tep(s[i++]-'0',next);
           s+=tep;
           next=!(next-'1')+'1';
       }
       return count(s.begin(),s.begin()+n,'1');
    }
};
