class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(!len||s[0]=='0')return 0;
        int cur=1,pre=1,ppre;
        for(int i=1;i<len;i++){
            ppre=pre;
            pre=cur;
            if(s[i]=='0'){
                if(s[i-1]=='1'||s[i-1]=='2')cur=ppre;
                else return 0;
            }
            else{
            int tep=stoi(s.substr(i-1,2));
            if(tep>=11&&tep<=26)cur=ppre+pre;
            else cur=pre;
            }
        }
        return cur;
    }
};
