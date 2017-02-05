class Solution {
public:
    bool check_IP4(string &IP){
        int len=IP.size();
        if(IP[len-1]=='.')return false;
        int start=0;
        int cur=start;
        int cnt=0;
        for(;cur<len;cur++){
            while(cur<len&&IP[cur]!='.'){
                if(IP[cur]<'0'||IP[cur]>'9')return false;
                cur++;
            }
            if(cur-start==0||cur-start>3||(IP[start]=='0'&&(cur-start)>1))return false;
            int n=stoi(IP.substr(start,cur-start));
            if(n>255)return false;
            start=cur+1;
            cnt++;
        }
        return cnt==4;
    }
    
    bool check_IP6(string &IP){
        int len=IP.size();
        if(IP[len-1]==':')return false;
        int start=0;
        int cur=start;
        int cnt=0;
        for(;cur<len;cur++){
            while(cur<len&&IP[cur]!=':'){
                if(!((IP[cur]>='0'&&IP[cur]<='9')||(IP[cur]>='a'&&IP[cur]<='f')||(IP[cur]>='A'&&IP[cur]<='F')))return false;
                cur++;
            }
            if(cur-start==0||cur-start>4)return false;
            start=cur+1;
            cnt++;
        }
        return cnt==8;
    }
    
    string validIPAddress(string IP) {
        for(int i=0;i<IP.size();i++){
            if(IP[i]=='.'){
                if(check_IP4(IP))return "IPv4";
                else return "Neither";
            }
            else if(IP[i]==':'){
                if(check_IP6(IP))return "IPv6";
                else return "Neither";
            }
        }
        return "Neither";
    }
};
