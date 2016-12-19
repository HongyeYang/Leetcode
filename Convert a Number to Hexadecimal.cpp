class Solution {
public:
    string toHex(int num) {
        if(!num)return "0";
        string res;
        int k=0;
        while(num&&k<8){
            int cur=num&15;
            num>>=4;
            if(cur>9){
                res.push_back('a'+cur-10);
            }
            else res.push_back('0'+cur);
            k++;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
