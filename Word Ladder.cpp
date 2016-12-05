class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> roc;
        roc.push(beginWord);
        roc.push("");
        int res=1;
        while(roc.size()>1){
            while(roc.front()!=""){
                string cur=roc.front();
                roc.pop();
                for(int i=0;i<cur.size();i++){
                    char c=cur[i];
                    for(int j=0;j<26;j++){
                        cur[i]='a'+j;
                        if(cur[i]==c)continue;
                        if(cur==endWord)return ++res;
                        if(wordList.find(cur)!=wordList.end()){
                            roc.push(cur);
                            wordList.erase(cur);
                        }
                    }
                    cur[i]=c;
                }
            }
            roc.pop();
            roc.push("");
            res++;
        }
        return 0;
    }
};
