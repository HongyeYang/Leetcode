class Solution {
public:
    struct TrieNode{
      string str;
      TrieNode *child[26];
      TrieNode():str(""){
          for(auto &a:child)a=NULL;
      }
    };
    
    struct Trie{
        TrieNode* root;
        Trie():root(new TrieNode()){}
        void insert(string s){
            TrieNode* p=root;
            for(auto &c:s){
                if(p->child[c-'a']==NULL)p->child[c-'a']=new TrieNode();
                p=p->child[c-'a'];
            }
            p->str=s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //corner cases
        if(!board.size()||!board[0].size()||!words.size())return {};
        //prepare the data-structure
        Trie T;
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        vector<string>res;
        //fill the Trie T
        for(auto &w:words)T.insert(w);
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(T.root->child[board[i][j]-'a'])search(board,T.root->child[board[i][j]-'a'],i,j,visited,res);
            }
        }
        return res;
    }
    
    void search(vector<vector<char>>&board,TrieNode* &t,int i,int j,vector<vector<bool>>&visited,vector<string>&res ){
        if(!t->str.empty()){
            res.push_back(t->str);
            t->str.clear();
        }
        visited[i][j]=true;
        //neibors search
        //up
        if(i>0&&visited[i-1][j]==false&&t->child[board[i-1][j]-'a'])search(board,t->child[board[i-1][j]-'a'],i-1,j,visited,res);
        //down
        if(i<board.size()-1&&visited[i+1][j]==false&&t->child[board[i+1][j]-'a'])search(board,t->child[board[i+1][j]-'a'],i+1,j,visited,res);
        //left
        if(j>0&&visited[i][j-1]==false&&t->child[board[i][j-1]-'a'])search(board,t->child[board[i][j-1]-'a'],i,j-1,visited,res);
        //right
        if(j<board[0].size()-1&&visited[i][j+1]==false&&t->child[board[i][j+1]-'a'])search(board,t->child[board[i][j+1]-'a'],i,j+1,visited,res);
        
        visited[i][j]=false;
        return;
    }
};
