class Solution {
public:
    void DST(vector<string>&res,string& cur,int k,string s){
        int len=s.size();
        
        if(k==1){
            if(s[0]=='0'&&len>1)return;
            int num=stoi(s);
            if(num<256){
                cur=cur+s;
                res.push_back(cur);
            }
            return;
        }
        if(s[0]=='0'){
            cur=cur+"0"+".";
            DST(res,cur,k-1,s.substr(1));
            return;
        }
        int minlen=max(len-3*(k-1),1),maxlen=min(len-k+1,3);
        for(int i=minlen;i<=maxlen;i++){
            int num=stoi(s.substr(0,i));
            if(num<256){
                string tep;
                tep=cur+s.substr(0,i)+".";
                DST(res,tep,k-1,s.substr(i));
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        if(s.size()<4)return res;
        string cur;
        DST(res,cur,4,s);
        return res;
    }
};
