class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num=strs.size();
        string res;
        if(!num||!strs[0].size())return res;
        int i=0;
        while(i<strs[0].size()){
            char c=strs[0][i];
            for(int j=1;j<num;j++){
                if(i==strs[j].size()||c!=strs[j][i])return res;
            }
            res.push_back(c);
            i++;
        }
        return res;
    }
};
