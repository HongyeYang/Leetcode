class Solution {
public:
    int romanToInt(string s) {
        int len=s.size(),i=0,res=0;
            while(s[i]=='M'){res+=1000;i++;if(i==len)return res;}
            if(i<len-1&&s.substr(i,2)=="CM"){res+=900;i+=2;if(i==len)return res;}
            if(s[i]=='D'){res+=500;i++;if(i==len)return res;}
            if(i<len-1&&s.substr(i,2)=="CD"){res+=400;i+=2;if(i==len)return res;}
            while(s[i]=='C'){res+=100;i++;if(i==len)return res;}
            if(i<len-1&&s.substr(i,2)=="XC"){res+=90;i+=2;if(i==len)return res;}
            if(s[i]=='L'){res+=50;i++;if(i==len)return res;}
            if(i<len-1&&s.substr(i,2)=="XL"){res+=40;i+=2;if(i==len)return res;}
            while(s[i]=='X'){res+=10;i++;if(i==len)return res;}
            if(i<len-1&&s.substr(i,2)=="IX"){res+=9;i+=2;if(i==len)return res;}
            if(s[i]=='V'){res+=5;i++;if(i==len)return res;}
            if(i<len-1&&s.substr(i,2)=="IV"){res+=4;i+=2;if(i==len)return res;}
            while(s[i]=='I'){res+=1;i++;if(i==len)return res;}
            return res;
    }
};
