class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>s(10,0);
        vector<int>g(10,0);
        int A=0,B=0;
        int len=secret.size();
        for(int i=0;i<len;i++){
            if(secret[i]==guess[i])A++;
            s[secret[i]-'0']++;
            g[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++)B+=min(s[i],g[i]);
        string res=to_string(A)+"A"+to_string(B-A)+"B";
        return res;
    }
};
