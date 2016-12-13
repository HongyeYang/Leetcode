class Solution {
public:
    string add(string s1,string s2){
        string res;
        int flag=0;
        if(s1.size()<s2.size())swap(s1,s2);
        s2=string(s1.size()-s2.size(),'0')+s2;
        for(int i=s1.size()-1;i>=0;i--){
            int tep=s1[i]-'0'+s2[i]-'0'+flag;
            res=to_string(tep%10)+res;
            flag=tep/10;
        }
        if(flag)res="1"+res;
        return res;
    }
    bool DST(string& num, int start,string ppre,string pre,int minlen){
        if(start+minlen>num.size()||num[start]=='0')return false;
        if(num.substr(start,minlen)==add(ppre,pre)){
            if(start+minlen==num.size()||DST(num,start+minlen,pre,num.substr(start,minlen),minlen))return true;
        }
        if(start+minlen>=num.size())return false;
        if(num.substr(start,minlen+1)==add(ppre,pre)){
            if(start+minlen+1==num.size()||DST(num,start+minlen+1,pre,num.substr(start,minlen+1),minlen+1))return true;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        int len=num.size();
        if(!len)return false;
        for(int i=0;i<len/2;i++){
            for(int j=i+1;j<len-i-1;j++){
                if(num[i+1]=='0'&&j-i>1)break;
                int minlen=max(i+1,j-i);
                if(DST(num,j+1,num.substr(0,i+1),num.substr(i+1,j-i),minlen))return true;
            }
        }
        return false;
    }
};
