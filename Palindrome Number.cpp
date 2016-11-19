class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string tep=to_string(x);
        int len=tep.size();
        int i=0,j=len-1;
        while(i<j){
            if(tep[i]!=tep[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
