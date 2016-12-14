class Solution {
public:
    string reverseString(string s) {
        int len=s.size();
        int i=0,j=len-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};
