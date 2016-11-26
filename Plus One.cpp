class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size(),sig=0;
        for(int i=0;i<len;i++){
            int tep;
            if(!i)tep=digits[len-1-i]+1+sig;
            else tep=digits[len-1-i]+sig;
            sig=0;
            if(tep>=10){
                sig=1;
                tep-=10;
            }
            digits[len-1-i]=tep;
            if(!sig)return digits;
        }
        if(sig)digits.insert(digits.begin(),1);
        return digits;
    }
};
