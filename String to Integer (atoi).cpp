class Solution {
public:
    int myAtoi(string str) {
        int len=str.size();
        if(!len)return 0;
        int i=0,flag=0;
        while(str[i]==' ')i++;
        if(str[i]=='+'||str[i]=='-'){
            if(str[i]=='-')flag=-1;
            else flag=1;
            i++;
        }
        long res=0;
        while(i<len&&str[i]>='0'&&str[i]<='9'){
        res=res*10+(str[i]-'0');
        if(flag>=0&&res>INT_MAX)return INT_MAX;
        if(flag<0&&res>=2147483648)return INT_MIN;
        i++;
        }
        return flag<0?-res:res;
    }
};
