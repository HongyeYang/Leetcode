class Solution {
public:
    int findNthDigit(int n) {
        //find num of digits
        int base=1,ltnum=9;
        long limit=9;
        while(n>limit){
            base++;
            ltnum+=9*pow(10,base-1);
            limit+=9*pow(10,base-1)*base;
        }
        //determine the number
        int num=ltnum-(limit-n)/base;
        //find the digit
        int ord=(limit-n)%base,res=0;
        while(ord>-1){
            res=num%10;
            num/=10;
            ord--;
        }
        return res;
    }
};
