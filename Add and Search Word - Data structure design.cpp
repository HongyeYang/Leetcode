class WordDictionary {
public:
    struct TrieNode{
        public:
        TrieNode* child[26];
        bool end;
        TrieNode(){
            end=false;
            for(auto &a:child)a=NULL;
        }
    };
    TrieNode* root=new TrieNode();
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur=root;
        for(char c:word){
            if(!cur->child[c-'a'])cur->child[c-'a']=new TrieNode();
            cur=cur->child[c-'a'];
        }
        cur->end=true;
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool step(string& word, TrieNode* rt,int start){
        int len=word.size();
        if(start==len)return rt->end;
            if(word[start]=='.'){
                for(auto& kk:rt->child){
                    if(kk&&step(word,kk,start+1))return true;
                }
            }
            else{
                if(!rt->child[word[start]-'a'])return false;
                return step(word,rt->child[word[start]-'a'],start+1);
            }
            return false; 
        }
    
    bool search(string word) {
        return step(word,root,0);
    }
};
