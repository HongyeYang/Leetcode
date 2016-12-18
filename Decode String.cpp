class Solution {
public:
    string decodeString(string s) {
        string res;
        int len=s.size();
        if(!len)return res;
        int n=0,cnt=0;
        for(int i=0;i<len;i++){
            if(s[i]>='0'&&s[i]<='9'){
                int start=i;
                while(s[i]>='0'&&s[i]<='9')i++;
                n=stoi(s.substr(start,i-start));
                start=i+1;
                while(i<len){
                    if(s[i]=='[')cnt++;
                    else if(s[i]==']'){
                        cnt--;
                        if(!cnt)break;
                    }
                    i++;
                }
                string tep=decodeString(s.substr(start,i-start));
                while(n--){
                    res=res+tep;
                }
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};
