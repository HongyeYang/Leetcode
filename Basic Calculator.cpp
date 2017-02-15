class Solution {
public:
    int calculate(string s) {
        int res=0;
        vector<int>sign{1,1};
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(s[i]>='0'&&s[i]<='9'){
                int end=i+1;
                while(s[end]>='0'&&s[end]<='9')end++;
                res+=(sign.back()*stoi(s.substr(i,end-i)));
                i=end-1;
                sign.pop_back();
            }
            else if(s[i]==')')sign.pop_back();
            else sign.push_back(sign.back()*(s[i]=='-'?-1:1));
            
        }
        return res;
    }
};
