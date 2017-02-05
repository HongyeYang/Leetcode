class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len=str.size();
        for(int i=1;i<=len/2;i++){
            if(len%i)continue;
            string s=str.substr(0,i);
            int start=i;
            while(start<len){
                if(str.substr(start,i)!=s)break;
                else{
                start+=i;
                    if(start==len)return true;
                }
            }
        }
        return false;

    }
};
