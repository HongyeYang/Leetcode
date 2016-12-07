class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len=s.size();
        if(!len)return false;
        vector<bool>roc(len+1,false);
        roc[0]=true;
        for(int i=0;i<len;i++){
            for(int j=0;j<=i;j++){
                if(wordDict.find(s.substr(j,i-j+1))!=wordDict.end()&&roc[j]){
                    roc[i+1]=true;
                    break;
                }
            }
        }
        return roc[len];
    }
};
