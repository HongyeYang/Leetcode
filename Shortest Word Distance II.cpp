class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i=0;i<words.size();i++){
            roc[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>&v1=roc[word1];
        vector<int>&v2=roc[word2];
        int res=INT_MAX;
        int i=0,j=0;
        for(;i<v1.size();i++){
            while(j<v2.size()-1&&v2[j]<v1[i]){
                res=min(res,abs(v2[j]-v1[i]));
                j++;
            }
            res=min(res,abs(v2[j]-v1[i]));
        }
        return res;
    }
private:
unordered_map<string,vector<int>>roc;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
