class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char,string>c2s;
        unordered_map<string,char>s2c;
        return dfs(pattern,0,str,0,c2s,s2c);
    }
    
    bool dfs(string &pattern, int pp, string &str, int ps,unordered_map<char,string>&c2s, unordered_map<string,char>&s2c){
        if(pp==pattern.size()&&ps==str.size())return true;
        if((int)pattern.size()-pp>(int)str.size()-ps||pp==pattern.size())return false;
        if(c2s.count(pattern[pp])){
            string t=c2s[pattern[pp]];
            if(str.substr(ps,(int)t.size())==t)return dfs(pattern,pp+1,str,ps+(int)t.size(),c2s,s2c);
            else return false;
        }
        else{
            for(int len=1;len<=str.size()-ps;len++){
                if(s2c.count(str.substr(ps,len)))continue;
                string ns=str.substr(ps,len);
                s2c[ns]=pattern[pp];
                c2s[pattern[pp]]=ns;
                if(dfs(pattern,pp+1,str,ps+len,c2s,s2c))return true;
                s2c.erase(ns);
            }
            c2s.erase(pattern[pp]);
            return false;
        }
    }
};
