class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>roc(numRows,"");
        if(!s.size()||numRows<2)return s;
        int currow=0,sign=1;
        for(char c:s){
            roc[currow].push_back(c);
            currow+=sign;
            if(currow==0||currow==numRows-1)sign*=-1;
        }
        string res;
        for(string cur:roc)res+=cur;
        return res;
    }
};
