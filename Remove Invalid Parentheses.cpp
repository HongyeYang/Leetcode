class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if(s.size()==0)return {""};
        queue<string>q;
        unordered_set<string>existed;
        vector<string>res;
        q.push(s);
        while(!q.empty()){
            string tar=q.front();
            q.pop();
            if(existed.find(tar)!=existed.end())continue;
            existed.insert(tar);
            int idx=FindInvalidIndex(tar);
            if(idx==-1){
                res.push_back(tar);
                continue;
            }
            char c=tar[idx];
            int start=0;
            int end=tar.size()-1;
            if(c=='(')start=idx;
            else end=idx;
            for(int i=start;i<=end;i++){
                if(tar[i]!=c)continue;
                if(i>start&&tar[i]==tar[i-1])continue;
                string ntar=tar.substr(0,i)+tar.substr(i+1);
                q.push(ntar);
            }
        }
        return res;
    }
    
    int FindInvalidIndex(string &s){
        int count=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                st.push(i);
            }
            else if(s[i]==')'){
                if(count==0)return i;
                count--;
                st.pop();
            }
        }
        if(st.empty())return -1;
        return st.top();
    }
};
