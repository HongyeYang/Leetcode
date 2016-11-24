class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len=digits.size();
        if(!len)return {};
        unordered_map<char,string>roc;
        roc['2']="abc";
        roc['3']="def";
        roc['4']="ghi";
        roc['5']="jkl";
        roc['6']="mno";
        roc['7']="pqrs";
        roc['8']="tuv";
        roc['9']="wxyz";
        vector<string>res;
        for(char c :digits){
            if(roc.find(c)==roc.end())return {};
            string cur=roc[c];
            int lenc=cur.size(),lenr=res.size();
            if(!lenr){
                for(int kk=0;kk<lenc;kk++)res.push_back(cur.substr(kk,1));
            }
            else{
            for(int j=0;j<lenc-1;j++){
                for(int k=0;k<lenr;k++){
                    string tep=res[k];
                    tep.push_back(cur[j]);
                    res.push_back(tep);
                }
            }
            for(int k=0;k<lenr;k++)res[k].push_back(cur[lenc-1]);
            }
        }
        return res;
    }
};
