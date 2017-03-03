class Solution {
public:
    bool canWin(string s) {
        return dfs(s);
    }
    bool dfs(string &s){
        for(int i=1;i<s.size();i++){
            if(s[i]=='+'&&s[i-1]=='+'){
                s[i-1]='-';
                s[i]='-';
                if(!dfs(s)){
                    s[i]='+';
                    s[i-1]='+';
                    return true;
                }
                s[i]='+';
                s[i-1]='+';
            }
        }
        return false;
    }
};
