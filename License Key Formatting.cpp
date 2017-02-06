class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ns;
        int m=0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]!='-'){
                if(S[i]>='a'&&S[i]<='z')S[i]+=('A'-'a');
                ns.push_back(S[i]);
                m++;
                if(m==K){
                    ns.push_back('-');
                    m=0;
                }
            }
        }
        if(ns.back()=='-')ns.pop_back();
        reverse(ns.begin(),ns.end());
        return ns;
    }
};
