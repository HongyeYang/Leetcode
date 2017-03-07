class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(string &w:d){
            int i=0;
            for(char &c:s){
                if(c==w[i])i++;
                if(i==w.size()){
                    if((int)w.size()>(int)res.size()||((int)w.size()==(int)res.size()&&w<res))res=w;
                    break;
                }
            }
        }
        return res;
    }
};
