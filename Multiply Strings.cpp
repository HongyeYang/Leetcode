class Solution {
public:
    string add(string &s1,string &s2){
        int len1=s1.size(),len2=s2.size(),dig=0;
        if(!len1)return s2;
        if(!len2)return s1;
        string res;
        int len=max(len1,len2);
        for(int i=0;i<len;i++){
            int k1,k2;
            if(i>len1-1)k1=0;
            else k1=s1[len1-1-i]-'0';
            if(i>len2-1)k2=0;
            else k2=s2[len2-1-i]-'0';
            int tep=k1+k2+dig;
            dig=0;
            if(tep>=10){
                dig=1;
                tep-=10;
            }
            res.push_back(tep+'0');
        }
        if(dig)res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
        }
    string multiply(string num1, string num2) {
        int len1=num1.size(),len2=num2.size();
        if(!len1||!len2)return {};
        if(num1=="0"||num2=="0")return "0";
        string res;
        for(int i=0;i<len1;i++){
            string cur(i,'0');
            int curdig=num1[len1-1-i]-'0',dig=0;
            for(int j=0;j<len2;j++){
                int tep=(num2[len2-1-j]-'0')*curdig+dig;
                dig=tep/10;
                tep%=10;
                cur.push_back(tep+'0');
            }
            if(dig)cur+=to_string(dig);
            reverse(cur.begin(),cur.end());
            res=add(res,cur);
        }
        return res;
    }
};
