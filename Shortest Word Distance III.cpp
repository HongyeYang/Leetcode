class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int len=words.size();
        int res=INT_MAX;
        unordered_map<string,int>roc;
        if(word1==word2){
            roc[word1]=-len*2;
            for(int i=0;i<len;i++){
                if(roc.count(words[i])){
                    res=min(res,abs(i-roc[words[i]]));
                    roc[words[i]]=i;
                }
            }
        }
        else{
            roc[word1]=2*len;
            roc[word2]=-2*len;
            for(int i=0;i<len;i++){
                auto it=roc.find(words[i]);
                if(it!=roc.end()){
                    it->second=i;
                    if(it==roc.begin()){
                        it++;
                        res=min(res,abs(it->second-i));
                    }
                    else{
                        res=min(res,abs(i-roc.begin()->second));
                    }
                }
            }
        }
        return res;
    }
};
