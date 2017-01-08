class Solution {
public:
    int longestPalindrome(string s) {
        int res=0,flag=0;
        vector<int>roc(256,0);
        for(char c:s){
            if(roc[c]){
                res+=2;
                roc[c]=0;
                flag--;
            }
            else{
                roc[c]++;
                flag++;
            }
        }
        return flag?res+1:res;
    }
};
