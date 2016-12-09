class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator)return "0";
        string res;
        long long num=numerator;
        long long den=denominator;
        if(num<0^den<0)res+="-";
        num=abs(num);
        den=abs(den);
        
        long long cur=num/den;
        res+=to_string(cur);
        num%=den;
        if(!num)return res;
        res+=".";
        unordered_map<long long,int>roc;
        int flag=res.size();
        int dig=flag;
        while(num){
            if(roc.find(num)!=roc.end()){
                res.insert(res.begin()+roc[num],'(');
                res.push_back(')');
                break;
            }
            else{
                roc[num]=dig;
                dig++;
                res+=to_string(num*10/den);
                num=num*10%den;
            }
        }
        return res;
    }
};
