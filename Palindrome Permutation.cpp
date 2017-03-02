class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>roc(128,0);
        for(char c:s)roc[c]++;
        bool single=false;
        for(int n:roc){
            if(n&1){
                if(single)return false;
                single=true;
            }
        }
        return true;
    }
};
