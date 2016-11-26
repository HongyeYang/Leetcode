class Solution {
public:
    string addBinary(string a, string b) {
        int lena=a.size(),lenb=b.size(),len=max(lena,lenb);
        if(!lena)return b;
        if(!lenb)return a;
        int sig=0;
        string res;
        for(int i=0;i<len;i++){
            int tep;
            if(i>=lena){
                tep=b[lenb-1-i]-'0'+sig;
            }
            else if(i>=lenb){
                tep=a[lena-1-i]-'0'+sig;
            }
            else{
                tep=a[lena-1-i]-'0'+b[lenb-1-i]-'0'+sig;
            }
            sig=0;
            if(tep>=2){
                sig=1;
                tep-=2;
            }
            res=to_string(tep)+res;
        }
        if(sig)res="1"+res;
        return res;
    }
};
