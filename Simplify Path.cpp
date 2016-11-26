class Solution {
public:
    string simplifyPath(string path) {
        int len=path.size();
        if(len<2)return "/";
        stack<string>roc;
        string cur;
        for(int i=1;i<=len;i++){
            if(path[i]=='/'||i==len){
                while(i<len-1&&path[i+1]=='/')i++;
                if(cur==".."&&(!roc.empty()))roc.pop();
                else if(cur!="."&&cur!=".."&&cur.size())roc.push(cur);
                cur="";
            }
            else cur.push_back(path[i]);
        }
        while(!roc.empty()){
            string kk=roc.top();
            roc.pop();
            cur=kk+"/"+cur;
        }
        cur="/"+cur;
        cur.pop_back();
        return cur.empty()?"/":cur;
    }
};
