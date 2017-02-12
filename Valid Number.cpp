class Solution {
public:
    bool isNumber(string s) {
        int len=s.size();
        if(!len)return false;
        //init start,end
        int start=0,end=len-1;
        while(start<len&&s[start]==' ')start++;
        while(end>=0&&s[end]==' ')end--;
        if(s[start]=='-'||s[start]=='+')start++;
        if(end<start)return false;

        //ini e,dot n
        int en=0,dn=0,n=0;
        for(;start<=end;start++){
            if(!en){
                if(s[start]>='0'&&s[start]<='9')n++;
                else if(s[start]=='e'){
                    if(!n)return false;
                    en++;
                    n=0;
                    if(start<end&&(s[start+1]=='-'||s[start+1]=='+'))start++;
                }
                else if(s[start]=='.'){
                    dn++;
                    if(dn>1)return false;
                }
                else return false;
            }
            else{
                if(s[start]>='0'&&s[start]<='9')n++;
                else return false;
            }
        }
        return n;
    }
};
