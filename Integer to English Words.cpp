class Solution {
public:
    string numberToWords(int num) {
        //prepare for name vector
        vector<string>lessThan20={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string>Tens={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        vector<string>Units={"","Thousand","Million","Billion"};
        
        if(!num)return "Zero";
        string res;
        int d=0;
        while(num>0){
            int cur=num%1000;
            if(cur)res=lessThanThousand(cur,lessThan20,Tens)+" "+Units[d]+" "+res;
            d++;
            num/=1000;
        }
        while(res.back()==' ')res.pop_back();
        return res;
    }
    string lessThanThousand(int n,vector<string>&lessThan20,vector<string>&Tens){
        string res;
        if(n>99){
            res+=(lessThan20[n/100]+" Hundred ");
            n=n%100;
        }
        if(n>19){
            res+=(Tens[n/10]+" ");
            n=n%10;
        }
        res+=lessThan20[n];
        while(res.back()==' ')res.pop_back();
        return res;
    }
};
