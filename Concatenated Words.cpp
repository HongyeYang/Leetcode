class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>roc(words.begin(),words.end());
        vector<string>res;
        
        for(string &word:words){
            int n=word.size();
            vector<bool>dp(n+1,false);
            dp[0]=true;
            
            for(int i=0;i<n;i++){
                if(!dp[i])continue;
                for(int j=i+1;j<=n;j++){
                    if(j-i<n&&roc.count(word.substr(i,j-i)))dp[j]=true;
                }
                if(dp[n]){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};
