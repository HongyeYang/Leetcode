class Solution {
public:
    void dfs(string &s, string &path, int l, int r, int idx, vector<string>&res){
        if(r>l)return;
        if(idx==s.size()&&(res.empty()||path.size()==res[0].size())&&l==r){
            res.push_back(path);
            return;
        }
        if(idx==s.size())return;
        if(res.size()>0&&path.size()+s.size()-idx<res[0].size())return;
        char c=s[idx++];
        //keep s[idx]
        path.push_back(c);
        if(c=='(')dfs(s,path,l+1,r,idx,res);
        else if(c==')')dfs(s,path,l,r+1,idx,res);
        else dfs(s,path,l,r,idx,res);
        
        //out of c
        path.pop_back();
        if(c=='('||c==')'){
            while(c==s[idx])idx++;
            dfs(s,path,l,r,idx,res);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        string path;
        dfs(s,path,0,0,0,res);
        return res.size()==0?vector<string>{""}:res;
    }
};
