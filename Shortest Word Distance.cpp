class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,int>roc;
        int res=INT_MAX;
        int len=words.size();
        roc[word1]=(-2*len);
        roc[word2]=2*len;
        for(int i=0;i<len;i++){
            auto it=roc.find(words[i]);
            if(it!=roc.end()){
                it->second=i;
                if(it==roc.begin())it++;
                else it=roc.begin();
                res=min(res,abs(i-it->second));
            }
        }
        return res;
    }
};
