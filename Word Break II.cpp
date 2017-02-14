class Solution {
public:
    void recur(string &s,unordered_set<string>& dict, vector<bool>&canBreak, string& cur, int start,vector<string>&res,int &len){
        if(start==len){
            res.push_back(cur.substr(0,cur.size()-1));
        }
        else{
            for(int i=start;i<len;i++){
                string word=s.substr(start,i-start+1);
                if(canBreak[i+1]&&dict.find(word)!=dict.end()){
                    cur.append(word).append(" ");
                    int oldsize=res.size();
                    recur(s,dict,canBreak,cur,i+1,res,len);
                    if(res.size()==oldsize)canBreak[i+1]=false;
                    cur=cur.substr(0,cur.size()-word.size()-1);
                }
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len=s.size();
        vector<bool>canBreak(len+1,true);
        //init dict
        unordered_set<string>dict;
        for(int i=0;i<wordDict.size();i++)dict.insert(wordDict[i]);
        
        vector<string>res;
        string cur="";
        
        recur(s,dict,canBreak,cur,0,res,len);
        return res;
    }
};
