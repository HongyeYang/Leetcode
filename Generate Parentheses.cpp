class Solution {
public:
    void DST(int i,int j,string cur,vector<string>&res){
        if(!i&&!j){res.push_back(cur);return;}
        if(!i){
            cur.push_back(')');
            DST(i,j-1,cur,res);
        }
        else{
            cur.push_back('(');
            DST(i-1,j,cur,res);
            if(i<j){
            cur.pop_back();
            cur.push_back(')');
            DST(i,j-1,cur,res);
            }
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        if(!n)return {};
        vector<string>res;
        string cur;
        DST(n,n,cur,res);
        return res;
    }
};
