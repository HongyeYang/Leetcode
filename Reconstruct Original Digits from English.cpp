class Solution {
public:
    string originalDigits(string s) {
        vector<int>roc(26,0);
        for(auto c:s)roc[c-'a']++;
        vector<int>dig(10,0);
        dig[0]=roc['z'-'a'];
        dig[6]=roc['x'-'a'];
        dig[4]=roc['u'-'a'];
        dig[2]=roc['w'-'a'];
        dig[5]=roc['f'-'a']-dig[4];
        dig[3]=roc['r'-'a']-dig[4]-dig[0];
        dig[1]=roc['o'-'a']-dig[2]-dig[4]-dig[0];
        dig[7]=roc['s'-'a']-dig[6];
        dig[8]=roc['g'-'a'];
        dig[9]=(roc['n'-'a']-dig[1]-dig[7])/2;
        
        string res;
        for(int i=0;i<10;i++){
            if(dig[i]){
                string cur(dig[i],'0'+i);
                res+=cur;
            }
        }
        return res;
        
    }
};
