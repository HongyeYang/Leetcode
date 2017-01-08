class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size()){
            string ad(num1.size()-num2.size(),'0');
            num2=ad+num2;
        }
        else if(num2.size()>num1.size()){
            string ad(num2.size()-num1.size(),'0');
            num1=ad+num1;
        }
        int flag=0;
        string res;
        for(int i=num1.size()-1;i>=0;i--){
            int tep=num1[i]+num2[i]-'0'-'0'+flag;
            flag=0;
            if(tep>=10){
                tep-=10;
                flag=1;
            }
            res=to_string(tep)+res;
        }
        if(flag)res="1"+res;
        return res;
    }
};
