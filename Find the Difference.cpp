class Solution {
public:
    char findTheDifference(string s, string t) {
        int roc=0;
        for(char c:s)roc=roc^c;
        for(char c:t)roc=roc^c;
        return (char)roc;
    }
};
