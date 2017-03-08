class Solution {
public:
    bool canWin(string s) {
        unordered_map<string,bool>roc;
        return dfs(s,roc);
    }
    
    bool dfs(string &s,unordered_map<string,bool>&roc){
        if((int)s.size()<2)return false;
        for(int i=1;i<s.size();i++){
            if(s[i]=='+'&&s[i-1]=='+'){
                s[i-1]='-';
                s[i]='-';
                if(!roc.count(s))roc[s]=dfs(s,roc);
                bool valid=roc[s];
                s[i]='+';
                s[i-1]='+';
                if(!valid){
                    roc[s]=true;
                    return true;
                }
            }
        }
        roc[s]=false;
        return false;
    }
};
