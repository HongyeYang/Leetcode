class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[26];
    bool end;
    TrieNode() {
        for(auto &a:child)a=NULL;
        end=false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur=root;
        for(char c:word){
            if(!cur->child[c-'a'])cur->child[c-'a']=new TrieNode();
            cur=cur->child[c-'a'];
        }
        cur->end=true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur=root;
        for(char c:word){
            if(!cur->child[c-'a'])return false;
            cur=cur->child[c-'a'];
        }
        return cur->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char c:prefix){
            if(!cur->child[c-'a'])return false;
            cur=cur->child[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
