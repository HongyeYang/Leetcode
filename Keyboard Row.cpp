class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int>roc{2,1,1,2,3,2,2,2,3,2,2,2,1,1,3,3,3,3,2,3,3,1,3,1,3,1};
        int flag=-1;
        vector<string>res;
        for(int i=0;i<words.size();i++){
            flag=roc[tolower(words[i][0])-'a'];
            for(int j=0;j<words[i].size();j++){
                if(flag!=roc[tolower(words[i][j])-'a']){
                    flag=-1;
                    break;
                }
            }
            if(flag>-1)res.push_back(words[i]);
        }
        return res;
    }
};
