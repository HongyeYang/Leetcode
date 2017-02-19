class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        if(words.size()<3)return {};
        unordered_set<string>roc(words.begin(),words.end());
        for(string &word:words){
            if(dfs(roc,word,0,0))res.push_back(word);
        }
        return res;
    }
    
    bool dfs(unordered_set<string>&roc,string&word,int start,int cnt){
        if(start==word.size()&&cnt>=2)return true;
        for(int i=start+1;i<=word.size();i++){
            if(roc.count(word.substr(start,i-start))){
                if(dfs(roc,word,i,cnt+1))return true;
            }
        }
        return false;
    }
};
