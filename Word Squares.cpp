class Solution {
private:
struct TrieNode{
    vector<int>index;
    TrieNode* child[26];
    TrieNode():index(vector<int>{}){
        for(auto &c:child)c=NULL;
    }
};

struct Trie{
    TrieNode* root;
    Trie():root(new TrieNode()){};
    void insert(vector<string>&dict){
        for(int k=0;k<dict.size();k++){
            TrieNode* cur=root;
            string &s=dict[k];
            for(int i=0;i<s.size();i++){
                if(cur->child[s[i]-'a']==NULL)cur->child[s[i]-'a']=new TrieNode();
                cur=cur->child[s[i]-'a'];
                cur->index.push_back(k);
            }
        }
    }
};

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        Trie T;
        T.insert(words);
        vector<string>cur(words[0].size());
        vector<vector<string>>res;
        for(int i=0;i<words.size();i++){
            cur[0]=words[i];
            dfs(T.root,1,words,cur,res);
        }
        return res;
    }
    
    void dfs(TrieNode* root,int level,vector<string>&words,vector<string>&cur,vector<vector<string>>&res){
        if(level>=words[0].size()){
            res.push_back(cur);
            return;
        }
        
        string pre;
        for(int i=0;i<level;i++)pre.push_back(cur[i][level]);
        TrieNode* c=root;
        for(char p:pre){
            if(c->child[p-'a']==NULL)return;
            c=c->child[p-'a'];
        }
        
        for(int idx:c->index){
            cur[level]=words[idx];
            dfs(root,level+1,words,cur,res);
        }
        return;
    }
};
